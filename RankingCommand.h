#ifndef RANKINGCOMMAND_H
#define RANKINGCOMMAND_H

#include "Command.h"

class RankingCommand : public Command {
public:
	RankingCommand() : Command("ranking") {}
	virtual void execute(CommunicationSocket* socket);
	virtual bool available(CommunicationSocket* socket);
};

#endif