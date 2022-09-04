#include "vector_map/adas_reader.hpp"

namespace vector_map
{
bool ADASReader::readPointCSV(const std::string& csv_name)
{
  return this->adas_points_.readCSV(csv_name);
}
}
