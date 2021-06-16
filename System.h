#ifndef SYSTEM_H
#define SYSTEM_H

#include "WordBank.h"
#include "User.h"
#include "Communication.h"
#include <vector>


class System : public WordBank{
	friend class InputHandler;
	//friend class CommunicationSocket;
	friend class RegisterCommand;
	friend class LoginCommand;
	friend class AddWordCommand;
	friend class StartCommand;
	friend class ForgotPwdCommand;
	friend class RankingCommand;
	friend class SaveStateCommand;
	friend class LoadStateCommand;
	
private:
	static int nextId;
	const std::string SysFilename;
	std::vector<User*> mUsers;
	void loadSysFromFile();
	User* findById(int id);
	User* findByUsername(std::string username);
	User* findByEmail(std::string email);
	void addUser(User* uPtr) { uPtr->mId = System::nextId++; this->mUsers.push_back(uPtr); }
	void incScore(int id) { this->findById(id)->mScore++; }
	void changePwd(User* uPtr, std::string pwd) { uPtr->mPwdHash = AntoHash::getHash(pwd); }
public:
	System() : SysFilename("UsersDB.txt") {this->loadSysFromFile(); }
	void writeSysToFile();
	virtual ~System();
	void showRanking();
};

#endif