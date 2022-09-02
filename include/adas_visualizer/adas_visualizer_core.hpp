#include "vector_map/adas_reader.hpp"

// ROS
#include <ros/ros.h>

class ADASVisualizer
{
public:
  ADASVisualizer(ros::NodeHandle nh) : nh_(nh)
  {}

  void run();

private:
  ros::NodeHandle nh_;
};
