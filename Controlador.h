#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
using Levels::Level;

class Controlador
{
private:
	Level* lvlref;
	sf::Keyboard::Key p1left;
	sf::Keyboard::Key p1right;
	sf::Keyboard::Key p1up;
	sf::Keyboard::Key p1down;
	sf::Keyboard::Key p1attack1;
	sf::Keyboard::Key p1attack2;

	sf::Keyboard::Key pause;

	sf::Keyboard::Key p2left;
	sf::Keyboard::Key p2right;
	sf::Keyboard::Key p2up;
	sf::Keyboard::Key p2down;
	sf::Keyboard::Key p2attack1;
	sf::Keyboard::Key p2attack2;
public:
	Controlador(Level* ref);
	void getInput();
};

