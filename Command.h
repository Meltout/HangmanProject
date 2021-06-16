#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <iostream>
#include "Communication.h"

class Command {
protected:
	std::string mName;
public:
	Command(std::string name) : mName(name) {}
	virtual void execute(CommunicationSocket *socket) = 0;
	virtual bool available(CommunicationSocket* socket) = 0;
	virtual ~Command() = default;
	std::string getName() { return this->mName; }
};


#endif