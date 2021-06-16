#include "WordBank.h"

void WordBank::addWord(std::string word)
{
	for(std::string& s: this->bank)
		if (s == word)
		{
			std::cerr << word << " is already in the Word Bank" << std::endl;
			return;
		}
	this->bank.push_back(word);
	std::cout << "Successfully added " << word << std::endl;
}

void WordBank::rmvWord(std::string word)
{
	for (size_t i = 0; i < this->bank.size(); i++)
		if (this->bank[i] == word)
		{
			this->bank.erase(this->bank.begin() + i);
			std::cout << "Successfully removed " << word << std::endl;
			return;
		}
	std::cerr << word << " is not in the Word Bank" << std::endl;
}

std::string WordBank::sampleWord() const
{
	return this->bank[rand() % this->bank.size()];
}

void WordBank::writeBankToFile() const
{
	std::ofstream out(this->WBfilename, std::ios::out, std::ios::trunc);
	if (out.is_open())
	{
		out << this->bank.size() << std::endl;
		for (const std::string& s : this->bank)
			out << s << std::endl;
		out.close();
		std::cout << "Successfully saved WordBank" << std::endl;
	}
	else
		throw std::exception("Error encountered when opening WordBank file");
}

void WordBank::loadBankFromFile()
{
	std::ofstream makeSureItExists;
	makeSureItExists.open(this->WBfilename, std::ios::out | std::ios::app);
	if(makeSureItExists.is_open())
		makeSureItExists.close();

	std::ifstream in(this->WBfilename, std::ios::in);
	if (in.is_open())
	{
		if (Utils::isEmpty(in))
		{
			in.close();
			std::cout << "Successfully loaded WordBank" << std::endl;
		}
		else
		{
			size_t sz;
			in >> sz;
			this->bank.resize(sz);
			for (size_t i = 0; i < sz; i++)
				in >> this->bank[i];
			in.close();
			std::cout << "Successfully loaded WordBank" << std::endl;
		}
	}
	else
		throw std::exception("Error encountered when opening WordBank file");
}

WordBank::~WordBank()
{
	this->writeBankToFile();
}

