#ifndef COMMUNICATION_H
#define COMMUNICATION_H

class System;
class ExitCommand;
class RegisterCommand;
class GameState;

/// This acts as the communication pathway
/// between us and the system
class CommunicationSocket {
	friend class System;
	friend class InputHandler;
	friend class ExitCommand;
	friend class RegisterCommand;
	friend class LoginCommand;
	friend class LogoutCommand;
	friend class AddWordCommand;
	friend class StartCommand;
	friend class ForgotPwdCommand;
	friend class RankingCommand;
	friend class SaveStateCommand;
	friend class LoadStateCommand;
private:
	int mLoggedId;
	GameState* mGS;
	System* mSys;
public:
	CommunicationSocket(System* sys) : mLoggedId(-1), mGS(nullptr), mSys(sys) {}
	bool isOnline() { return this->mSys != nullptr; }
	~CommunicationSocket();
};

#endif