#include "vector_map/point.hpp"

namespace vector_map
{
std::pair<int, ADASPoint> ADASPoints::getElementFromStr(const std::vector<std::string>& str_vec)
{
  int id;
  ADASPoint p;
  try
  {
    id = std::stoi(str_vec[0]);
    p.lat = std::stod(str_vec[1]);
    p.lon = std::stod(str_vec[2]);
    p.h = std::stod(str_vec[3]);
    p.x = std::stod(str_vec[4]);
    p.y = std::stod(str_vec[5]);
    p.crs = str_vec[6];
    p.mcode1 = std::stoi(str_vec[7]);
    p.mcode2 = std::stoi(str_vec[8]);
    p.mcode3 = std::stoi(str_vec[9]);
  }
  catch(const std::exception& e)
  {
    std::cerr << "Error while reading point CSV" << std::endl;
    std::cerr << e.what() << '\n';
    exit(1);
  }

  return std::pair<int, ADASPoint>(id, p);
}
}
