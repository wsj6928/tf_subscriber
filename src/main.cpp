#include <ros/ros.h>
#include <tf/transform_listener.h>
#include "std_msgs/String.h"

int main(int argc, char **argv)
{

	ros::init(argc, argv, "tf_subscriber");
	ros::NodeHandle nh;
	tf::TransformListener listener;
	ros::Rate loop_rate(10.0);
	while ((ros::ok()))
	{
		tf::StampedTransform transform;
		try
		{
			listener.lookupTransform("camera_aligned_depth_to_color_frame","qr_link",
									 ros::Time(0), transform);
		}
		catch (tf::TransformException ex)
		{
			ROS_ERROR("%s", ex.what());
		}

		double x =transform.getOrigin().x();
		double y =transform.getOrigin().y();
		double z =transform.getOrigin().z();
		tf::Quaternion q = transform.getRotation();
		double qx = q.x();
		double qy = q.y();
		double qz = q.z();
		double qw = q.w();

		printf("x: %f, y: %f, z: %f, qx: %f,qy: %f,qz: %f, qw: %f\n",x,y,z,qx,qy,qz,qw);


		loop_rate.sleep();
	}

	return 0;
}
