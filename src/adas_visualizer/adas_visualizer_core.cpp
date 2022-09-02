#include "adas_visualizer/adas_visualizer_core.hpp"

void ADASVisualizer::run()
{
  std::cout << "Spinning!" << std::endl;
  ros::spin();
  std::cout << "Finish!" << std::endl;
}
