#ifndef COLORED_BUFFER_H
#define COLORED_BUFFER_H

#include <string>
#include <vector>
#include <regex>

class ColoredBuffer {
    static const std::vector<std::string> keyWords, identifiers;
    std::vector<std::vector<int> > colors;
	public:
	  //copy the buffer over and generate the color vector
	  ColoredBuffer(const std::vector<std::string> &buffer);
      std::vector<int> getColor(size_t i);
};
#endif

