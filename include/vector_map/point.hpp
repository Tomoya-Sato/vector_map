#ifndef ADAS_POINT_HPP
#define ADAS_POINT_HPP

#include <string>
#include <vector>
#include <unordered_map>

namespace vector_map
{
struct ADASPoint
{
  double lat_, lon_;  // Latitude, Longitude
  double h_;  // Height
  double x_, y_;  // X, Y in some CRS
  std::string crs_;   // Coordinate Reference System
  int mcode1_, mcode2_, mcode3_;
};

class ADASPoints
{
public:
  ADASPoints();
  ADASPoints(const std::string& csv_name);
  void clear()
  {
    this->points_.clear();
    this->id_vec_.clear();
  }
  bool readCSV(const std::string& csv_name);
  bool addPoint(const int& id, const ADASPoint& p);
  int size() { return this->points_.size(); }
  int getID(const int& i) { return this->id_vec_[i]; }
  ADASPoint getPointByID(const int& id) { return this->points_[id]; }

private:
  std::unordered_map<int, ADASPoint> points_;
  std::vector<int> id_vec_;
};
}

#endif