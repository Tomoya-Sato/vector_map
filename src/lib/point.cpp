#include "vector_map/point.hpp"

#include <iostream>
#include <fstream>

#include "vector_map/common.hpp"

namespace vector_map
{
ADASPoints::ADASPoints()
{
  this->clear();
}

ADASPoints::ADASPoints(const std::string& csv_name)
{
  this->clear();

  this->readCSV(csv_name);
}

bool ADASPoints::readCSV(const std::string& csv_name)
{
  this->clear();

  std::ifstream ifs(csv_name);

  std::string current_line;

  // Skip header line
  std::getline(ifs, current_line);
  while (std::getline(ifs, current_line))
  {
    std::vector<std::string> str_vec = splitCSV(current_line, ',');

    // CSV column size must be 10
    if (str_vec.size() != 10)
    {
      std::cerr << "Error: CSV column size is not 10" << std::endl;
      return false;
    }

    int id;
    ADASPoint p;
    try
    {
      id = std::stoi(str_vec[0]);
      p.lat_ = std::stod(str_vec[1]);
      p.lon_ = std::stod(str_vec[2]);
      p.h_ = std::stod(str_vec[3]);
      p.x_ = std::stod(str_vec[4]);
      p.y_ = std::stod(str_vec[5]);
      p.crs_ = str_vec[6];
      p.mcode1_ = std::stoi(str_vec[7]);
      p.mcode2_ = std::stoi(str_vec[8]);
      p.mcode3_ = std::stoi(str_vec[9]);
    }
    catch(const std::exception& e)
    {
      std::cerr << "Error while reading CSV: " << csv_name << std::endl;
      std::cerr << e.what() << '\n';

      return false;
    }

    this->addPoint(id, p);
  }

  ifs.close();

  return true;
}

bool ADASPoints::addPoint(const int& id, const ADASPoint& p)
{
  this->points_[id] = p;
  this->id_vec_.push_back(id);

  return true;
}
}
