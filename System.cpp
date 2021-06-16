#include "System.h"

int System::nextId = 1;

void System::loadSysFromFile()
{
	std::ofstream makeSureItExists;
	makeSureItExists.open(this->SysFilename, std::ios::out | std::ios::app);
	makeSureItExists.close();

	std::ifstream in(this->SysFilename, std::ios::in);
	if (in.is_open())
	{
		if (Utils::isEmpty(in))
		{
			std::cout << "Successfully loaded Users database" << std::endl;
			in.close();
		}
		else
		{
			size_t sz;
			in >> sz;
			this->mUsers.resize(sz);
			for (size_t i = 0; i < sz; i++)
			{
				int id;
				std::string username;
				std::string email;
				size_t pwdHash;
				int score;

				in >> id >> username >> email >> pwdHash >> score;
				this->mUsers[i] = new User(id, username, email, pwdHash, score);
				System::nextId = std::max(System::nextId, id + 1);
			}
			std::cout << "Successfully loaded Users database" << std::endl;
			in.close();
		}
	}

}

User* System::findById(int id)
{
	for (User* uPtr : this->mUsers)
		if (uPtr->mId == id)
			return uPtr;
	return nullptr;
}

User* System::findByUsername(std::string username)
{
	for (User* uPtr : this->mUsers)
		if (uPtr->mUsername == username)
			return uPtr;
	return nullptr;
}

User* System::findByEmail(std::string email)
{
	for (User* uPtr : this->mUsers)
		if (uPtr->mEmail == email)
			return uPtr;
	return nullptr;
}

void System::writeSysToFile()
{
	std::ofstream out(this->SysFilename, std::ios::out | std::ios::trunc);
	if (out.is_open())
	{
		out << this->mUsers.size() << std::endl;
		for (User* uPtr : this->mUsers)
			uPtr->writeTo(out);
		out.close();
		std::cout << "Successfully saved Users database" << std::endl;
	}
	else
		throw std::exception("Error encountered when opening UserDB.txt");
}

System::~System()
{
	this->writeSysToFile();
	for (User* uPtr : this->mUsers)
		delete uPtr;
}

void System::showRanking()
{
	for (size_t i = 0; i < this->mUsers.size(); i++)
		for (size_t j = i + 1; j < this->mUsers.size(); j++)
			if (*(this->mUsers[j]) < *(this->mUsers[i]))
				std::swap(this->mUsers[i], this->mUsers[j]);
	for (User* uPtr : this->mUsers)
		std::cout << uPtr->mUsername << ' ' << uPtr->mScore << std::endl;
}
