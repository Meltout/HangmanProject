#include "ForgotPasswordCommand.h"
#include "User.h"
#include "System.h"

void ForgotPwdCommand::execute(CommunicationSocket* socket)
{
	std::string username, email;
	std::cin >> username >> email;

	User* uPtr = socket->mSys->findByUsername(username);
	if (uPtr != nullptr)
	{
		if (uPtr->getEmail() == email)
		{
			std::cout << "Enter new password" << std::endl;
			std::string newPwd;
			std::cin >> newPwd;
			socket->mSys->changePwd(uPtr, newPwd);
			std::cout << "Password changed successfully" << std::endl;
		}
		else
			std::cerr << "Wrong Email" << std::endl;
	}
	else
		std::cerr << "Username not found" << std::endl;
}

bool ForgotPwdCommand::available(CommunicationSocket* socket)
{
	return (socket->mLoggedId == -1);
}
