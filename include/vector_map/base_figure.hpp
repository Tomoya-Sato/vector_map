#ifndef ADAS_BASE_FIGURE_HPP
#define ADAS_BASE_FIGURE_HPP

#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <unordered_map>

#include "vector_map/common.hpp"

namespace vector_map
{
template <typename T>
class ADASBase
{
public:
  ADASBase()
  {
    this->clear();
  }
  ADASBase(const std::string& csv_name)
  {
    this->clear();
    this->readCSV(csv_name);
  }

  void clear()
  {
    this->elements_.clear();
    this->id_vec_.clear();
  }
  bool addElement(const int& id, const T& element)
  {
    this->elements_[id] = element;
    this->id_vec_.push_back(id);

    return true;
  }
  int size()
  {
    return this->elements_.size();
  }
  int getID(const int& i)
  {
    return this->id_vec_[i];
  }
  T getElementByID(const int& id)
  {
    return this->elements_[id];
  }

  bool readCSV(const std::string& csv_name)
  {
    this->clear();

    std::ifstream ifs(csv_name);
    std::string current_line;

    // Skip header line
    std::getline(ifs, current_line);
    
    while (std::getline(ifs, current_line))
    {
      std::vector<std::string> str_vec = splitCSV(current_line, ',');

      std::pair<int, T> ret = getElementFromStr(str_vec);

      this->addElement(ret.first, ret.second);
    }

    ifs.close();

    return true;
  }

  virtual std::pair<int, T> getElementFromStr(const std::vector<std::string>& str_vec) = 0;

private:
  std::unordered_map<int, T> elements_;
  std::vector<int> id_vec_;
};
}

#endif
