#include "ExitCommand.h"

void ExitCommand::execute(CommunicationSocket* socket)
{
	socket->mSys = nullptr;
}
