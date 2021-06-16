#include "AddWordCommand.h"
#include "System.h"
#include "Utils.h"

void AddWordCommand::execute(CommunicationSocket* socket)
{
	std::string word;
	std::cin >> word;

	word = Utils::toLower(word);
	for(const char& c: word)
		if (!isalpha(c))
		{
			std::cerr << "Words should contain only alphabetic characters" << std::endl;
			return;
		}

	socket->mSys->addWord(word);
}

bool AddWordCommand::available(CommunicationSocket* socket)
{
	return socket->mLoggedId != -1;
}
