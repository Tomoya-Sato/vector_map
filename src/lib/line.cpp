#include "vector_map/line.hpp"

namespace vector_map
{
std::pair<int, ADASLine> ADASLines::getElementFromStr(const std::vector<std::string>& str_vec)
{
  int id;
  ADASLine l;
  try
  {
    id = std::stoi(str_vec[0]);
    l.bpid = std::stoi(str_vec[1]);
    l.fpid = std::stoi(str_vec[2]);
    l.blid = std::stoi(str_vec[3]);
    l.flid = std::stoi(str_vec[4]);
  }
  catch(const std::exception& e)
  {
    std::cerr << "Error while reading line CSV" << std::endl;
    std::cerr << e.what() << '\n';
    exit(1);
  }

  return std::pair<int, ADASLine>(id, l);
}
}
