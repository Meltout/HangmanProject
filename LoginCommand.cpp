#include "LoginCommand.h"
#include "User.h"
#include "System.h"
#include "AntoHash.h"

void LoginCommand::execute(CommunicationSocket* socket)
{
	std::string username, password;
	std::cin >> username >> password;

	User* uPtr = socket->mSys->findByUsername(username);
	if (uPtr != nullptr)
	{
		if (AntoHash::getHash(password) == uPtr->getPwdHash())
		{
			socket->mLoggedId = uPtr->getId();
			std::cout << "Login Successful" << std::endl;
		}
		else
			std::cerr << "Wrong username or password" << std::endl;
	}
	else
		std::cerr << "Wrong username or password" << std::endl;
}

bool LoginCommand::available(CommunicationSocket* socket)
{
	return socket->mLoggedId == -1;
}
