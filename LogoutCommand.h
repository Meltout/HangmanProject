#ifndef LOGOUTCOMMAND_H
#define LOGOUTCOMMAND_H

#include "Command.h"

class LogoutCommand : public Command {
public:
	LogoutCommand() : Command("logout") {}
	virtual void execute(CommunicationSocket* socket);
	virtual bool available(CommunicationSocket* socket);
};

#endif;