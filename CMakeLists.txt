cmake_minimum_required(VERSION 3.0.2)
project(tf_subscriber)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  tf
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES opencv_object_tracking
  CATKIN_DEPENDS roscpp std_msgs tf
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(tf_subscriber src/main.cpp)

target_link_libraries(tf_subscriber ${catkin_LIBRARIES})

