#ifndef ADAS_COMMON_HPP
#define ADAS_COMMON_HPP

#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> splitCSV(const std::string& str, const char& del)
{
  std::vector<std::string> ret;
  std::istringstream i_stream(str);

  std::string buf;
  while (std::getline(i_stream, buf, del))
    ret.push_back(buf);

  return ret;
}

#endif
