#ifndef ADAS_READER_HPP
#define ADAS_READER_HPP

#include "vector_map/point.hpp"

namespace vector_map
{
class ADASReader
{
public:
  bool readPointCSV(const std::string& csv_name);
  int getPointsNum() { return this->adas_points_.size(); }
  int getPointID(const int& i) { return this->adas_points_.getID(i); }
  ADASPoint getPointByID(const int& id) { return this->adas_points_.getPointByID(id); }

private:
  ADASPoints adas_points_;
};
}

#endif
