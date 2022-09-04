#include "adas_visualizer/adas_visualizer_core.hpp"

ADASVisualizer::ADASVisualizer(ros::NodeHandle nh)
{
  this->nh_ = nh;
  this->marker_pub_ = nh_.advertise<visualization_msgs::Marker>("vector_map", 1, true);
}

void ADASVisualizer::readPointCSV(const std::string& csv_name)
{
  if (!this->adas_reader_.readPointCSV(csv_name))
  {
    // Cannot read point CSV
    exit(1);
  }

  this->is_point_ready_ = true;
}

void ADASVisualizer::publishPoint()
{
  if (!this->is_point_ready_)
  {
    std::cerr << "point is not ready" << std::endl;
    return;
  }

  visualization_msgs::Marker points_msg;
  points_msg.header.frame_id = "map";
  points_msg.header.stamp = ros::Time::now();
  points_msg.ns = "vector_map_point";
  points_msg.action = visualization_msgs::Marker::ADD;
  points_msg.id = 0;
  points_msg.type = visualization_msgs::Marker::POINTS;
  points_msg.scale.x = 0.1;
  points_msg.scale.y = 0.1;
  points_msg.scale.z = 0.1;
  points_msg.color.g = 1.0;
  points_msg.color.a = 1.0;

  for (int i = 0; i < this->adas_reader_.getPointsNum(); i++)
  {
    int id = this->adas_reader_.getPointID(i);
    vector_map::ADASPoint p = this->adas_reader_.getPointByID(id);

    geometry_msgs::Point q;
    q.x = p.x_;
    q.y = p.y_;
    q.z = p.h_;

    points_msg.points.push_back(q);
  }

  this->marker_pub_.publish(points_msg);
  ROS_INFO("Published point markers");
}

void ADASVisualizer::run()
{
  std::cout << "Spinning!" << std::endl;
  ros::spin();
  std::cout << "Finish!" << std::endl;
}
