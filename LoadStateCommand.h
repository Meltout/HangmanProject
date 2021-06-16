#ifndef LOADSTATECOMMAND_H
#define LOADSTATECOMMAND_H

#include "Command.h"

class LoadStateCommand : public Command {
public:
	LoadStateCommand() : Command("load") {}
	virtual void execute(CommunicationSocket* socket);
	virtual bool available(CommunicationSocket* socket);
};

#endif