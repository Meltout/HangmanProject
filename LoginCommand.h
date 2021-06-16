#ifndef LOGINCOMMAND_H
#define LOGINCOMMAND_H

#include "Command.h"

class LoginCommand : public Command {
public:
	LoginCommand() : Command("login") {};
	virtual void execute(CommunicationSocket* socket);
	virtual bool available(CommunicationSocket* socket);
};

#endif