cmake_minimum_required(VERSION 2.8.3)
project(vector_map)

# Enable support for C++14
if (${CMAKE_VERSION} VERSION_LESS "3.1.0")
  set(CMAKE_CXX_FLAGS "{CMAKE_CXX_FLAGS} -std=c++14")
else ()
  set(CMAKE_CXX_STANDARD 14)
endif ()

find_package(catkin REQUIRED COMPONENTS
  roscpp
  visualization_msgs
)

catkin_package(
  LIBRARIES vector_map
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
)
link_directories(${PCL_LIBRARY_DIRS})

add_library(vector_map
  src/lib/adas_reader.cpp
  src/lib/point.cpp
  src/lib/line.cpp
)
target_link_libraries(vector_map ${catkin_LIBRARIES})

add_executable(adas_visualizer
  src/adas_visualizer/adas_visualizer_node.cpp
  src/adas_visualizer/adas_visualizer_core.cpp
)
target_link_libraries(adas_visualizer vector_map ${catkin_LIBRARIES})