#include "User.h"

User::User(std::string username, std::string email, std::string password) :
	mUsername(username), mEmail(email), mPwdHash(AntoHash::getHash(password)), mId(-1), mScore(0) {}

User::User(int id, std::string username, std::string email, int pwdHash, int score) :
	mId(id), mUsername(username), mEmail(email), mPwdHash(pwdHash), mScore(score) {}

bool User::operator<(const User& other) const
{
	if (this->mScore != other.mScore)
		return this->mScore > other.mScore;
	return this->mUsername < other.mUsername;
}


bool User::validate(std::string username, std::string email, std::string password)
{
	if (username.size() == 0 || username.size() >= 20)
	{
		std::cerr << "Username length must be between 1 and 20" << std::endl;
		return false;
	}
	if (email.size() == 0 || email.size() >= 20)
	{
		std::cerr << "Email length must be between 1 and 20" << std::endl;
		return false;
	}
	if (password.size() < 6)
	{
		std::cerr << "Password length must be at least 6" << std::endl;
		return false;
	}
	return true;
}

void User::writeTo(std::ostream &os)
{
	os << this->mId << ' ' << this->mUsername << ' ' << this->mEmail << ' ' 
		<< this->mPwdHash << ' ' << this->mScore << std::endl;

}

