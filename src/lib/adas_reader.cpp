#include "vector_map/adas_reader.hpp"

namespace vector_map
{
bool ADASReader::readCSV(const std::string& path_name)
{
  if (!readPointCSV(path_name + "/point.csv"))
    return false;

  if (!readLineCSV(path_name + "/line.csv"))
    return false;

  return true;
}

std::vector<ADASPoint> ADASReader::getLinePointsByID(const int& id)
{
  ADASLine line = this->getLineByID(id);

  std::vector<ADASPoint> point_vec(2);

  ADASPoint p1 = this->getPointByID(line.bpid);
  point_vec[0] = p1;

  ADASPoint p2 = this->getPointByID(line.fpid);
  point_vec[1] = p2;

  return point_vec;
}
}
