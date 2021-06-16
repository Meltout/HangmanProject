#include "GameState.h"
#include "InputHandler.h"
#include "System.h"
#include "Utils.h"

int main()
{

	System sys;
	CommunicationSocket socket(&sys);
	InputHandler inpHandler;
	std::cout << "Type \"available\" to see a list of available commands at any given moment" << std::endl;
	while (socket.isOnline())
	{
		std::string command;
		std::cin >> command;
		command = Utils::toLower(command);
		inpHandler.actOn(command, &socket);
	}

	
	return 0;
}