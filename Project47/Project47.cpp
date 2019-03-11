#include <iostream>
#include <string>

enum class Weapon
{
	SWORD,
	DAGGER,
	SHIELD,
	EMPTY,
};

struct Weap
{
	std::string name;
	Weapon type;
	int dmg;
};

struct Player
{
	std::string name;
	Weap weapR;
	Weap weapL;
	int health;
};

void introducePlayers(Player p1, Player p2)
{
	std::cout << p1.name << " has entered the arena with " << p1.health << " health and the " << p1.weapR.name << "!\n" << std::endl;
	std::cout << "The crowd obviously cheers uncontrollably... \n" << std::endl;
	std::cout << p2.name << " has entered the arena with " << p2.health << " health and " << p2.weapR.name << "!\n" << std::endl;
	std::cout << "AAAAAAAAAAAAAND nobody cares... \n" << std::endl;
}

void startBattle(Player p1, Player p2)
{
	std::cout
		<< "*****************************************\n"
		<< "The battle is ready to begin!!!  Press the ENTER key to START THE FIGHT!!!"
		<< "\n*****************************************\n";

	std::cin.get();

	int p1Health{ p1.health };
	int p2Health{ p2.health };

	std::cout << p2.name << " goes first, press the Enter key to attack!!!\n";
	std::cin.get();

	while (p2Health > 1 && p1Health > 1)
	{
		std::cout << p2.name << " attacks " << p1.name << " with " << p2.weapR.name << "!\n";
		std::cout << p1.name << " takes " << p2.weapR.dmg << " damage!\n";

		p1Health = p1Health - p2.weapR.dmg;
		std::cout << p1.name << "'s health: " << p1Health << '\n' << '\n';

		std::cout << p2.name << "'s turn is up!  Press enter for the next attack!!!\n";
		std::cin.get();

		std::cout << p1.name << " attacks " << p2.name << " with " << p1.weapR.name << "!\n";
		std::cout << p2.name << " takes " << p1.weapR.dmg << " damage!\n";

		p2Health = p2Health - p1.weapR.dmg;
		std::cout << p2.name << "'s health: " << p2Health << '\n' << '\n';

		std::cout << p1.name << "'s turn is up!  Press enter for the next attack!!!\n";
		std::cin.get();

	}

	if (p1Health < 1)
		std::cout << p2.name << " wins!!!\n";
	else if (p2Health < 1)
		std::cout << p1.name << " wins!!!\n";
	else
		std::cout << "Well the game is fucked up...";

	std::cout << "That's it...  Press Enter to end the program and stuff...";
	std::cin.get();
}


int main()
{
	Weap noWep = { "These Hands", Weapon::EMPTY, 5 };
	Weap endOF = { "Ender of Fools", Weapon::SWORD, 20 };
	Player p1 = { "Helliarc", endOF, noWep, 500 };
	Player p2 = { "Miscni", noWep, noWep, 40 };

	introducePlayers(p1, p2);
	startBattle(p1, p2);

	return 0;
}