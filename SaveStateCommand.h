#ifndef SAVESTATECOMMAND_H
#define SAVESTATECOMMAND_H

#include "Command.h"

class SaveStateCommand : public Command {
public:
	SaveStateCommand() : Command("save") {}
	virtual void execute(CommunicationSocket* socket);
	virtual bool available(CommunicationSocket* socket);
};

#endif