#pragma once
#include "Buttons.h"
#include "Menu.h"
using namespace Buttons;

namespace Menus {
	class PauseMenu : public Menu {
	private:

	public:
		PauseMenu(sf::Vector2f size, sf::Vector2f pos, MenuHandler* ref);
		~PauseMenu();
		void function(float deltat);
		void drawMenu(sf::RenderWindow* window);
	};

	class RankingMenu : public Menu {
	private:

	public:
		RankingMenu(sf::Vector2f size, sf::Vector2f pos, MenuHandler* ref);
		~RankingMenu();
		void function(float deltat);
		void drawMenu(sf::RenderWindow* window);
	};

	class MainMenu : public Menu {
	private:

	public:
		MainMenu(sf::Vector2f size, sf::Vector2f pos, MenuHandler* ref);
		~MainMenu();
		void function(float deltat);
		void drawMenu(sf::RenderWindow* window);
	};
	
	class SelectionMenu : public Menu {
	private:

	public:
		SelectionMenu(sf::Vector2f size, sf::Vector2f pos, MenuHandler* ref);
		~SelectionMenu();
		void function(float deltat);
		void drawMenu(sf::RenderWindow* window);
	};
}