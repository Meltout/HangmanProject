#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include "AntoHash.h"

class System;

class User {
	friend class System;
private:
	std::string mUsername;
	std::string mEmail;
	size_t mPwdHash;
	int mId;
	int mScore;
public:
	User(std::string username, std::string email, std::string password);
	User(int id, std::string username, std::string email, int pwdHash, int score);
	bool operator <(const User& other) const;
	static bool validate(std::string username, std::string email, std::string password);
	void writeTo(std::ostream &os);
	size_t getPwdHash() { return this->mPwdHash; }
	int getId() { return this->mId; }
	std::string getEmail() { return this->mEmail; }
	std::string getUsername() { return this->mUsername; }
};

#endif