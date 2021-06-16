#include "AntoHash.h"

size_t AntoHash::getHash(const std::string& s)
{
    size_t result = 0, coef = 1;
    for (size_t i = 0; i < s.size(); i++, coef *= mPrimeNum)
        result += coef * ((int)s[i] + 1);
    return result;
}
