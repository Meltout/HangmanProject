#include "Utils.h"

std::string Utils::toLower(const std::string& s)
{
	std::string result = s;
	for (char& c : result)
		c = tolower(c);
	return result;
}

std::string Utils::toUpper(const std::string& s)
{
	std::string result = s;
	for (char& c : result)
		c = toupper(c);
	return result;
}
