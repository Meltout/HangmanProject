#include "SaveStateCommand.h"
#include "GameState.h"
#include "System.h"

void SaveStateCommand::execute(CommunicationSocket* socket)
{
	std::string filename = (socket->mSys->findById(socket->mLoggedId))->getUsername();
	filename += "_" + std::to_string(socket->mGS->ASCIsum()) + ".hang";
	socket->mGS->writeToFile(filename);
}

bool SaveStateCommand::available(CommunicationSocket* socket)
{
	if (socket->mSys == nullptr || socket->mGS == nullptr || socket->mLoggedId == -1)
		return false;
	return !(socket->mGS->isWon() || socket->mGS->gameOver());
}
