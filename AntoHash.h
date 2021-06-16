#ifndef ANTOHASH_H
#define ANTOHASH_H

#include <string>

/// Приличен Overflow хеш, очаквам първата
/// колизия да се случи когато имаме
/// поне 30000 user-а
class AntoHash {
private:
	static const size_t mPrimeNum = 277;
public:
	AntoHash() = delete;
	static size_t getHash(const std::string &s);
};

#endif