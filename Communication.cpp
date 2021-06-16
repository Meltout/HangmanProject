#include "Communication.h"
#include "GameState.h"
#include "System.h"

CommunicationSocket::~CommunicationSocket()
{
	delete this->mGS;
}
