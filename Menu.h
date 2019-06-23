#pragma once
#include "MenuButton.h"
#include <iostream>
#include <vector>
using namespace std;
class MenuHandler;
class Menu : public sf::RectangleShape
{
public:
	const int getI() { return i; }
	void add(MenuButton* element) { vectofButtons.push_back(element); }
	MenuButton* getElement(int i) { return vectofButtons[i]; }
	Menu(sf::Vector2f size, sf::Vector2f pos, MenuHandler* ref);
	virtual void drawMenu(sf::RenderWindow* window) = 0;
	virtual void function(float deltat) = 0;
	void select();
	void selector(float deltat);
	MenuHandler* getMHRef() { return MHref; }
	int getVecSize() { return vectofButtons.size(); }
	float timet;
	float times;
protected:
	MenuHandler* MHref;
	textureManager* textmanager;
	vector<MenuButton*> vectofButtons;
	int i;

};

