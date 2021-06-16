#include "GameState.h"
#include "Utils.h"

GameState::GameState(const std::string& word)
	: mWord(word), mWrongGuesses(0), mGameOver(false)
{
	for (size_t i = 0; i < 26; i++)
		this->mGuessed[i] = false;
	this->mGuessed[word[0] - 'a'] = true;
}

bool GameState::isWon() const
{
	for (const char& c : mWord)
		if (!this->mGuessed[(int)(c - 'a')])
			return false;
	return true;
}

void GameState::writeToFile(const std::string& filename) const
{
	std::ofstream out(filename, std::ios::out | std::ios::trunc);
	if (out.is_open())
	{
		out << this->mWord << std::endl;
		out << this->mWrongGuesses << std::endl;
		for (size_t i = 0; i < 26; i++)
			out << (this->mGuessed[i] ? '1' : '0');
		out << std::endl;

		std::cout << "Successfully saved to file " << filename << std::endl;
	}
	else
		throw std::exception("Could not open the specified file");
}

void GameState::loadFromFile(const std::string& filename)
{
	std::ifstream in(filename, std::ios::in);
	if (in.is_open())
	{
		in >> this->mWord;
		in >> this->mWrongGuesses;
		this->mGameOver = false;
		std::string temp;
		in >> temp;
		for (int i = 0; i < 26; i++)
			this->mGuessed[i] = (temp[i] == '0' ? false : true);

		std::cout << "Successfully loaded from file " << filename << std::endl;
	}
	else
		throw std::exception("Could not open the specified file");
}


namespace GSImages {
	const int IMG_CNT = 5;
	const int IMG_WIDTH = 16;
	const int IMG_HEIGHT = 10;
	const char hangImage[IMG_CNT][IMG_HEIGHT][IMG_WIDTH] =
	{
		{
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}
		},
		{
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}
		},
		{
			{' ', ' ', ' ', ' ', '-', '-', '-', '-', '-', '-', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}
		},
		{
			{' ', ' ', ' ', ' ', '-', '-', '-', '-', '-', '-', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}
		},
		{
			{' ', ' ', ' ', ' ', '-', '-', '-', '-', '-', '-', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '\\', '|', '/', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '/', ' ', '\\', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}
		},
	};

	void showImage(size_t id)
	{
		if (id >= GSImages::IMG_CNT)
		{
			std::cerr << "Invalid image ID" << std::endl;
			return;
		}
		for (int i = 0; i < GSImages::IMG_HEIGHT; i++)
		{
			for (int j = 0; j < GSImages::IMG_WIDTH; j++)
				std::cout << GSImages::hangImage[id][i][j];
			std::cout << std::endl;
		}
	}
};

void GameState::print() const
{
	for (size_t i = 0; i < this->mWord.size(); i++)
		std::cout << ((this->mGuessed[this->mWord[i] - 'a']) ? (char)toupper(this->mWord[i]) : '_');
	std::cout << std::endl;
	
	std::cout << "Guessed Letters :";
	for (size_t i = 0; i < 26; i++)
		if (this->mGuessed[i])
			std::cout << ' ' << (char)('A' + i);
	std::cout << std::endl;

	GSImages::showImage(this->mWrongGuesses);

	if (this->mGameOver)
		std::cout << "Game Over" << std::endl;
	else if (this->isWon())
		std::cout << "Congratulations, You guessed the word!" << std::endl;
	else
		std::cout << "Pick a letter --> ";
}

void GameState::play(char ch)
{
	if (this->gameOver() || this->isWon())
	{
		std::cerr << "This game has already finished" << std::endl;
		return;
	}
	if (this->mGuessed[(int)(ch - 'a')])
	{
		std::cerr << "You have already guessed the letter " << ch << std::endl;
		return;
	}
	this->mGuessed[(int)(ch - 'a')] = true;

	bool found = false;
	for(size_t i = 0; i < this->mWord.size(); i++)
		if (this->mWord[i] == ch)
		{
			found = true;
			break;
		}
	if (!found)
	{
		this->mWrongGuesses++;
		if (this->mWrongGuesses == 4)
			this->mGameOver = true;
	}

	this->print();
}

int GameState::ASCIsum()
{
	int result = 0;
	for (const char& c : this->mWord)
		result += (int)c;
	return result;
}
