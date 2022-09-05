#ifndef ADAS_LINE_HPP
#define ADAS_LINE_HPP

#include "vector_map/base_figure.hpp"

namespace vector_map
{
struct ADASLine
{
  int bpid, fpid;   // The first and last point ID
  int blid, flid;   // Former and latter line ID
};

class ADASLines : public ADASBase<ADASLine>
{
public:
  std::pair<int, ADASLine> getElementFromStr(const std::vector<std::string>& str_vec);
};
}

#endif
