// Brian Milian
// CPSC 120-12
// 2022-12-01
// brianmilian@csu.fullerton.edu
// @brian-250
//
// Lab 12-01
// Partners: @engenies
//
// Has two functions to check file extension and to build sine lookup table
//

#include "animated_gradient_functions.h"

#include <cmath>
#include <iostream>

bool HasMatchingFileExtension(const std::string& file_name,
                              const std::string& extension) {
  return ((file_name.size() >= extension.size()) &&
          (file_name.compare(file_name.size() - extension.size(),
                             extension.size(), extension) == 0));
  return false;
}

std::vector<double> BuildSineLookupTable(int image_width) {
  std::vector<double> lookup_table;
  double radian_step = M_PI / double(image_width);
  for (int column = 0; column < image_width; column++) {
    double value = sin(radian_step * column);
    lookup_table.push_back(value);
  }
  return lookup_table;
}
