#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Utils.h"

/// ����� ������� ������ ���� validation pipeline
/// ����� �� ���� �������� �� ����� GameState �����
/// � ������ ������������ �� GameState �������� ����
/// ������� �������
class GameState {
private:
	std::string mWord;
	int mWrongGuesses;
	bool mGameOver;
	bool mGuessed[26] = { false };
public:
	GameState() = default;
	GameState(const std::string& word);
	bool gameOver() { return mGameOver; }
	bool isWon() const;
	void writeToFile(const std::string& filename) const;
	void loadFromFile(const std::string& filename);
	void print() const;
	void play(char letter);
	int ASCIsum();
};


#endif