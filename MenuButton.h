#pragma once
#include <SFML/Graphics.hpp>
class Menu;
class textureManager;

class MenuButton : public sf::RectangleShape
{
protected:
	textureManager* textManager;
	Menu* Mref;
public:
	void startRed() { setFillColor(sf::Color::Red); }
	MenuButton(sf::Vector2f size, sf::Vector2f pos, Menu* ref);
	virtual void selected() = 0;
	Menu* getMref() { return Mref; }
};

