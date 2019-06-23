#include "MenuButton.h"
#include "Menu.h"
#include "textureManager.h"
MenuButton::MenuButton(sf::Vector2f size, sf::Vector2f pos, Menu* ref) : RectangleShape (size)
{
	textManager = textureManager::getInstance();
	setPosition(pos);
	this->Mref = ref;
}
