#include "Header.h"
#include "Menu.h"

Menu::Menu(std::string taskName, std::vector<std::string> menuList)
	: taskName(taskName), menuList(menuList)
{}

void Menu::displayTaskName() const
{
	system("cls");
	std::cout << "\n\t ===================================";
	std::cout << "\n\t " << taskName;
	std::cout << "\n\t ===================================";
}

void Menu::displayMenuList() const
{
	for (int i = 0; i < menuList.size(); i++) {
		std::cout << "\n\t" << i + 1;
		std::cout << " - " << menuList[i];
	}
	std::cout << "\n\t ====================================";
	std::cout << std::endl;
}

int Menu::getChoice() const
{
	int choice = 0;
	std::cout << "\n Make your choice: ";
	std::cin >> choice;
	return choice;
}

bool Menu::allowContinue() const
{
	char allow;
	std::cout << "\n Continue (y/n) ? - ";
	std::cin >> allow;
	return (allow == 'y');
}
