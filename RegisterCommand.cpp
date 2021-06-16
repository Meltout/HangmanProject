#include "RegisterCommand.h"
#include "System.h"

void RegisterCommand::execute(CommunicationSocket* socket)
{
	std::string username, email, password;
	std::cin >> username >> email >> password;
	
	if (socket->mSys->findByUsername(username) != nullptr)
	{
		std::cerr << "Username is already taken" << std::endl;
		return;
	}
	if (socket->mSys->findByEmail(email) != nullptr)
	{
		std::cerr << "Email is already taken" << std::endl;
		return;
	}

	socket->mSys->addUser(new User(username, email, password));
	std::cout << "Successfuly registered user " << username << std::endl;
}

bool RegisterCommand::available(CommunicationSocket* socket)
{
	return socket->mLoggedId == -1;
}
