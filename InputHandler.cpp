#include "InputHandler.h"
#include "MyCommands.h"
#include "GameState.h"
#include "System.h"

InputHandler::InputHandler()
{
	this->mJoystick["exit"] = new ExitCommand();
	this->mJoystick["register"] = new RegisterCommand();
	this->mJoystick["login"] = new LoginCommand();
	this->mJoystick["logout"] = new LogoutCommand();
	this->mJoystick["addword"] = new AddWordCommand();
	this->mJoystick["start"] = new StartCommand();
	this->mJoystick["forgotpwd"] = new ForgotPwdCommand();
	this->mJoystick["ranking"] = new RankingCommand();
	this->mJoystick["#"] = new SaveStateCommand();
	this->mJoystick["load"] = new LoadStateCommand();
}

InputHandler::~InputHandler()
{
	for (auto it : this->mJoystick)
		delete it.second;
}

void InputHandler::showAvailableCommands(CommunicationSocket *socket) const
{
	std::cout << "Available commands: " << std::endl;
	for (auto it : this->mJoystick)
		if (it.second->available(socket))
			std::cout << it.second->getName() << std::endl;
	std::cout << std::endl;
}

void InputHandler::actOn(std::string command, CommunicationSocket *socket)
{
	if (command == "available")
	{
		showAvailableCommands(socket);
		return;
	}
	if (command.size() == 1 && isalpha(command[0]))
	{
		if ((socket->mGS != nullptr) && !(socket->mGS->gameOver()) && !(socket->mGS->isWon()))
		{
			socket->mGS->play(command[0]);
			if (socket->mGS->isWon())
				socket->mSys->incScore(socket->mLoggedId);
		}
		else
			std::cerr << "Invalid Command" << std::endl;
		return;
	}
	if (this->mJoystick.find(command) == this->mJoystick.end())
		std::cerr << "Invalid command" << std::endl;
	else
		if (this->mJoystick[command]->available(socket))
			this->mJoystick[command]->execute(socket);
		else
			std::cerr << command << " is not available right now" << std::endl;
}
