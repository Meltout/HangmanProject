#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

/// ������ �� ������������� �� ���� �� �������������� �� ��������� 
/// ��������� ������������ �� std::map 
#include <map>
#include <string>
#include <iostream>
#include "Command.h"
#include "Communication.h"
#include "MyCommands.h"

/// InputHandler �� � ���� ���� joystick
/// �� ���� �������. ��������� � �� ��������
/// � ����� ������ �� ������ ����� ���� �����������
/// � ���������
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