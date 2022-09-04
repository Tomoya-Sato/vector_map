#include "adas_visualizer/adas_visualizer_core.hpp"

#include <ros/ros.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "ADASVisualizer");
  ros::NodeHandle nh;

  std::string point_csv(argv[1]);
  
  ADASVisualizer adas_vis(nh);

  adas_vis.readPointCSV(point_csv);
  adas_vis.publishPoint();
  adas_vis.run();

  return 0;
}
