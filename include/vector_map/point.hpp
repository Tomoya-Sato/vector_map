#ifndef ADAS_POINT_HPP
#define ADAS_POINT_HPP

#include <string>

#include "vector_map/base_figure.hpp"

namespace vector_map
{
struct ADASPoint
{
  double lat, lon;  // Latitude, Longitude
  double h;  // Height
  double x, y;  // X, Y in some CRS
  std::string crs;   // Coordinate Reference System
  int mcode1, mcode2, mcode3;
};

class ADASPoints : public ADASBase<ADASPoint>
{
public:
  std::pair<int, ADASPoint> getElementFromStr(const std::vector<std::string>& str_vec);
};
}

#endif
