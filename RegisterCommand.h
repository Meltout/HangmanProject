#ifndef REGISTERCOMMAND_H
#define REGISTERCOMMAND_H

#include "Command.h"


class RegisterCommand : public Command {
public:
	RegisterCommand() : Command("register") {}
	virtual void execute(CommunicationSocket* socket);
	virtual bool available(CommunicationSocket* socket);
	virtual ~RegisterCommand() = default;

};

#endif