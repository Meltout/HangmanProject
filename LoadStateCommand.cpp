#include "LoadStateCommand.h"
#include "Utils.h"
#include "GameState.h"

void LoadStateCommand::execute(CommunicationSocket* socket)
{
	delete socket->mGS;
	std::string filename;
	std::cin >> filename;
	std::ifstream checkExistance(filename, std::ios::in);
	if (checkExistance.is_open() && !Utils::isEmpty(checkExistance))
	{
		checkExistance.close();
		socket->mGS = new GameState();
		socket->mGS->loadFromFile(filename);
		socket->mGS->print();
		return;
	}
	else
		std::cerr << "Couldn't open " << filename << std::endl;
}

bool LoadStateCommand::available(CommunicationSocket* socket)
{
	return socket->mSys != nullptr;
}
