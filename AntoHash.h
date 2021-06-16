#ifndef ANTOHASH_H
#define ANTOHASH_H

#include <string>

/// �������� Overflow ���, ������� �������
/// ������� �� �� ����� ������ �����
/// ���� 30000 user-�
class AntoHash {
private:
	static const size_t mPrimeNum = 277;
public:
	AntoHash() = delete;
	static size_t getHash(const std::string &s);
};

#endif