#ifndef STARTCOMMAND_H
#define STARTCOMMAND_H

#include "Command.h"

class StartCommand : public Command {
public:
	StartCommand() : Command("start") {}
	virtual void execute(CommunicationSocket* socket);
	virtual bool available(CommunicationSocket* socket);
};

#endif