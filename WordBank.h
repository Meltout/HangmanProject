#ifndef WORDBANK_H
#define WORDBANK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Utils.h"

class WordBank {
private:
	const std::string WBfilename;
	std::vector <std::string> bank;
public:
	WordBank() : WBfilename("WordBank.txt") {this->loadBankFromFile(); }
	virtual ~WordBank();
	void addWord(std::string word);
	void rmvWord(std::string word);
	std::string sampleWord() const;
	void writeBankToFile() const;
	void loadBankFromFile();
};


#endif