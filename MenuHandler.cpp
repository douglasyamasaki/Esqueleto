#include "MenuHandler.h"

MenuHandler::MenuHandler() : pauseobj (sf::Vector2f (1366,768),sf::Vector2f(0,0),this) , 
rankingobj(sf::Vector2f(1366, 768), sf::Vector2f(0, 0), this), 
mainobj(sf::Vector2f(1366, 768), sf::Vector2f(0, 0), this),
selectionobj(sf::Vector2f(1366, 768), sf::Vector2f(0, 0), this)
{
	active = true;
	p2 = false;
	currentMenu = &mainobj;
}

MenuHandler::~MenuHandler()
{
	currentMenu = nullptr;
}
