#ifndef FORGOTPWDCOMMAND_H
#define FORGOTPWDCOMMAND_H

#include "Command.h"

class ForgotPwdCommand : public Command {
public:
	ForgotPwdCommand() : Command("forgotpwd") {}
	virtual void execute(CommunicationSocket* socket);
	virtual bool available(CommunicationSocket* socket);
};

#endif