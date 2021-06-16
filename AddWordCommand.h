#ifndef ADDWORDCOMMAHD_H
#define ADDWORDCOMMAND_H

#include "Command.h"

class AddWordCommand : public Command {
public:
	AddWordCommand() : Command("addword") {}
	virtual void execute(CommunicationSocket *socket);
	virtual bool available(CommunicationSocket *socket);
};


#endif