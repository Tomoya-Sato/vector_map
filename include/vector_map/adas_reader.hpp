#ifndef ADAS_READER_HPP
#define ADAS_READER_HPP

#include "vector_map/point.hpp"
#include "vector_map/line.hpp"

namespace vector_map
{
class ADASReader
{
public:
  // General
  bool readCSV(const std::string& path_name);

  // Point
  bool readPointCSV(const std::string& csv_name) {return this->adas_points_.readCSV(csv_name); }
  int getPointsNum() { return this->adas_points_.size(); }
  int getPointID(const int& i) { return this->adas_points_.getID(i); }
  ADASPoint getPointByID(const int& id) { return this->adas_points_.getElementByID(id); }

  // Line
  bool readLineCSV(const std::string& csv_name) { return this->adas_lines_.readCSV(csv_name); }
  int getLinesNum() { return this->adas_lines_.size(); }
  int getLineID(const int& i) { return this->adas_lines_.getID(i); }
  ADASLine getLineByID(const int& id) { return this->adas_lines_.getElementByID(id); }
  std::vector<ADASPoint> getLinePointsByID(const int& id);

private:
  ADASPoints adas_points_;
  ADASLines adas_lines_;
};
}

#endif
