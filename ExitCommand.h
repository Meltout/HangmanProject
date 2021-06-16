#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H

#include "Command.h"

class ExitCommand : public Command {
public:
	ExitCommand() : Command("exit") {}
	virtual void execute(CommunicationSocket* socket);
	virtual bool available(CommunicationSocket* socket) { return true; }
	virtual ~ExitCommand() = default;
};

#endif