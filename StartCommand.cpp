#include "StartCommand.h"
#include "System.h"
#include "GameState.h"

void StartCommand::execute(CommunicationSocket* socket)
{
    delete socket->mGS;
    socket->mGS = new GameState(socket->mSys->sampleWord());
    socket->mGS->print();
}  

bool StartCommand::available(CommunicationSocket* socket)
{
    return socket->mLoggedId != -1;
}
