#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

/// смятам че елегантността на кода за интерпретиране на командите 
/// оправдава използването на std::map 
#include <map>
#include <string>
#include <iostream>
#include "Command.h"
#include "Communication.h"
#include "MyCommands.h"

/// InputHandler ще е нещо като joystick
/// на гейм конзола. Разликата е че бутоните
/// в нашия случай са текста който пише потребителя
/// в конзолата
class InputHandler {
private:
	std::map <std::string, Command*> mJoystick;
public:
	InputHandler();
	~InputHandler();
	void showAvailableCommands(CommunicationSocket* socket) const;
	void actOn(std::string command, CommunicationSocket *socket);
};

#endif