#include "adas_visualizer/adas_visualizer_core.hpp"

ADASVisualizer::ADASVisualizer(ros::NodeHandle nh)
{
  this->nh_ = nh;
  this->point_pub_ = nh_.advertise<visualization_msgs::Marker>("points", 1, true);
  this->line_pub_ = nh_.advertise<visualization_msgs::Marker>("lines", 1, true);
}

void ADASVisualizer::readCSV(const std::string& path_name)
{
  if (!this->adas_reader_.readCSV(path_name))
  {
    // Cannot read point CSV
    exit(1);
  }
}

void ADASVisualizer::publishPoint()
{
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
    q.x = p.x;
    q.y = p.y;
    q.z = p.h;

    points_msg.points.push_back(q);
  }

  this->point_pub_.publish(points_msg);
  ROS_INFO("Published point markers");
}

void ADASVisualizer::publishLine()
{
  visualization_msgs::Marker line_msg;
  line_msg.header.frame_id = "map";
  line_msg.header.stamp = ros::Time::now();
  line_msg.ns = "vector_map_line";
  line_msg.action = visualization_msgs::Marker::ADD;
  line_msg.id = 1;
  line_msg.type = visualization_msgs::Marker::LINE_LIST;
  line_msg.scale.x = 0.05;
  line_msg.pose.orientation.w = 1.0;
  line_msg.color.b = 1.0;
  line_msg.color.a = 1.0;

  for (int i = 0; i < this->adas_reader_.getLinesNum(); i++)
  {
    int id = this->adas_reader_.getLineID(i);
    std::vector<vector_map::ADASPoint> point_vec = this->adas_reader_.getLinePointsByID(id);

    geometry_msgs::Point p1, p2;
    p1.x = point_vec[0].x;
    p1.y = point_vec[0].y;
    p1.z = point_vec[0].h;

    p2.x = point_vec[1].x;
    p2.y = point_vec[1].y;
    p2.z = point_vec[1].h;

    line_msg.points.push_back(p1);
    line_msg.points.push_back(p2);
  }

  this->line_pub_.publish(line_msg);
  ROS_INFO("Published line markers");
}

void ADASVisualizer::run()
{
  this->publishPoint();
  this->publishLine();

  std::cout << "Spinning!" << std::endl;
  ros::spin();
  std::cout << "Finish!" << std::endl;
}
