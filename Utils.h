#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <fstream>

class Utils {
public:
	Utils() = delete;
	static std::string toLower(const std::string &s);
	static std::string toUpper(const std::string& s);
	static bool isEmpty(std::ifstream& pFile){ return pFile.peek() == std::ifstream::traits_type::eof(); }
};

#endif