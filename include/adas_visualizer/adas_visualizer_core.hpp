#include "vector_map/adas_reader.hpp"

// ROS
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

class ADASVisualizer
{
public:
  ADASVisualizer(ros::NodeHandle nh);

  void readCSV(const std::string& path_name);
  void publishPoint();
  void publishLine();
  void run();

private:
  // ROS
  ros::NodeHandle nh_;
  ros::Publisher point_pub_;
  ros::Publisher line_pub_;

  vector_map::ADASReader adas_reader_;
};
