#include "RankingCommand.h"
#include "System.h"

void RankingCommand::execute(CommunicationSocket* socket)
{
	socket->mSys->showRanking();
}

bool RankingCommand::available(CommunicationSocket* socket)
{
	return socket->mSys != nullptr;
}
