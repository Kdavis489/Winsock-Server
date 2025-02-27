#include "Includes.h"
#include "Game.h"

Game::Game()
{
	choice = 0;
	playing = true;
	activeCharacter = 0;
	filename = "characters.txt";
}

Game::~Game()
{

}

void Game::mainMenu()
{

	std::cout << "MAIN MENU" << std::endl;
	std::cout << "0 Quit" << std::endl;
	std::cout << "1 shop" << std::endl;
	std::cout << "2 travel" << std::endl;
	std::cout << "rest" << std::endl;

	switch (choice)
	{
	case 0:
		playing = false;
		break;
	}
}

void Game::initGame()
{

}

void Game::createCharacter()
{
	std::string name = " ";
	std::cout << "Character name: ";
	getline(std::cin, name);

	for (size_t i = 0; i < this -> characters.size(); i++)
	{
		while (name == this->characters[i].getName())
		{
			std::cout << "Error! Character Already Exists!" << "\n";
			std::cout << "Character Name: ";
			getline(std::cin, name);
		}
	}
	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].Initialize(name);
}

void Game::loadCharacter()
{
	std::ifstream inFile(filename);

	this->characters.clear();

	std::string name = "";
	int level = 0;
	int exp = 0;
	int expNext = 0;
	int str = 0;
	int def = 0;
	int magi = 0;
	int speed = 0;
	//vitals
	int hp = 0;
	int hpMax = 0;
	int mp = 0;
	int mpMax = 0;
	int sp = 0;
	int spMax = 0;
	int stamina = 0;
	//stats
	int damageMin = 0;
	int damageMax = 0;
	int statPnt = 0;
	int skillpnt = 0;

	std::string line = "";
	std::stringstream strt;

	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			strt.str(line);
			strt >> name;
			strt >> level;
			strt >> exp;
			strt >> str;
			strt >> def;
			strt >> magi;
			strt >> speed;
			strt >> hp;
			strt >> mp;
			strt >> sp;
			strt >> stamina;
			strt >> statPnt;
			strt >> skillpnt;
			Character temp(name, level, exp, str, def, magi, speed, hp, mp, sp, stamina, statPnt, skillpnt);

		}
	}
	inFile.close();

	if (this->characters.size() <= 0)
	{
		throw "Error! NO CHARACTERS LOADED OR EMPTY FILE!";
	}
}

void Game::saveCharacter()
{
	std::ofstream outFile(filename);

	if (outFile.is_open())
	{
		for (size_t i = 0; i < this->characters.size(); i++)
		{
			outFile << this->characters[i].getAsString();
//			outFile << this->characters[i].getInvAsStringSave();
		}
	}
}

void Game::characterMenu()
{
}

void Game::selectCharacter()
{
	std::cout << "Select character:";
	for (size_t i = 0; i < this->characters.size() i++)
	{
		std::cout << "Index: " << i << " = " << this->characters[i].getName() << "level: " << this->characers[i].getLevel();
	}
}
