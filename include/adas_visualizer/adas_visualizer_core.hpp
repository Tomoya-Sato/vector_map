#include "vector_map/adas_reader.hpp"

// ROS
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

class ADASVisualizer
{
public:
  ADASVisualizer(ros::NodeHandle nh);

  void readPointCSV(const std::string& csv_name);
  void publishPoint();
  void run();

private:
  // ROS
  ros::NodeHandle nh_;
  ros::Publisher marker_pub_;

  vector_map::ADASReader adas_reader_;

  // Flags
  bool is_point_ready_ = false;
};
