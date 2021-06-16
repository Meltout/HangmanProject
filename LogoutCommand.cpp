#include "LogoutCommand.h"

void LogoutCommand::execute(CommunicationSocket* socket)
{
	socket->mLoggedId = -1;
	std::cout << "Logout successfull" << std::endl;
}

bool LogoutCommand::available(CommunicationSocket* socket)
{
	return (socket->mLoggedId != -1);
}
