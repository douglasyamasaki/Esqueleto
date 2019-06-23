#include "Menus.h"
#include "textureManager.h"
#include "MenuHandler.h"
Menus::PauseMenu::PauseMenu(sf::Vector2f size, sf::Vector2f pos, MenuHandler* refe) : Menu (size,pos,refe)
{
	setTexture(textmanager->getInstance()->getPauseMenu ());
	ButtonResume* resbutton = new ButtonResume(sf::Vector2f(200,200),sf::Vector2f(200,200),this);
	resbutton->startRed();
	ButtonReturn* retbutton = new ButtonReturn(sf::Vector2f(200, 200), sf::Vector2f(200, 450), this);
	ButtonSave* saveButton = new ButtonSave(sf::Vector2f(200, 200), sf::Vector2f(200, 450), this);
	add(resbutton);
	add(retbutton);
	add(saveButton);
	
}

Menus::PauseMenu::~PauseMenu()
{
	delete vectofButtons[1];
	delete vectofButtons[2];
	delete vectofButtons[0];
}

void Menus::PauseMenu::drawMenu(sf::RenderWindow* window)
{
	window->draw(*this);
	for (int k = 0; k < vectofButtons.size(); k++) {
		window->draw(*(vectofButtons[k]));
	}
}
void Menus::PauseMenu::function(float deltat) {
	selector(deltat);
	drawMenu(getMHRef()->getWindow());
	return;
}

Menus::RankingMenu::RankingMenu(sf::Vector2f size, sf::Vector2f pos, MenuHandler* ref) : Menu (size,pos,ref)
{
	setTexture(textmanager->getRankingMenu());
	ButtonReturn* retbutton = new ButtonReturn(sf::Vector2f(200, 200), sf::Vector2f(200, 200), this);
	retbutton->startRed();
	add(retbutton);
}

Menus::RankingMenu::~RankingMenu()
{
	delete vectofButtons[0];
}

void Menus::RankingMenu::function(float deltat)
{
	selector(deltat);
	drawMenu(getMHRef()->getWindow());
}

void Menus::RankingMenu::drawMenu(sf::RenderWindow* window)
{
	window->draw(*(this));
	window->draw(*vectofButtons[i]);
}

Menus::MainMenu::MainMenu(sf::Vector2f size, sf::Vector2f pos, MenuHandler* ref) : Menu (size,pos,ref)
{
	setTexture(textmanager->getMainMenu());
	Button1p* b1p = new Button1p(sf::Vector2f(200, 200), sf::Vector2f(183, 0),this);
	Button2p* b2p = new Button2p(sf::Vector2f(200, 200), sf::Vector2f(183, 220), this);
	ButtonLoad* buttonload = new ButtonLoad(sf::Vector2f(200, 200), sf::Vector2f(183, 420), this);
	ButtonHighscore* buttonhs = new ButtonHighscore(sf::Vector2f(200, 200), sf::Vector2f(483, 220), this);
	ButtonQuit* quitbutton = new ButtonQuit(sf::Vector2f(200, 200), sf::Vector2f(483, 420),this);
	b1p->startRed();
	add(b1p);
	add(b2p);
	add(buttonhs);
	add(buttonload);
	add(quitbutton);
}

Menus::MainMenu::~MainMenu()
{
	for (int k = 0; k < vectofButtons.size(); k++) {
		delete vectofButtons[k];
	}
}

void Menus::MainMenu::function(float deltat)
{
	selector(deltat);
	drawMenu(getMHRef()->getWindow());
	return;
}

void Menus::MainMenu::drawMenu(sf::RenderWindow* window)
{
	window->draw(*this);
	MHref->getView()->setCenter(this->getSize() / 2.0f);
	for (int k = 0; k < vectofButtons.size(); k++) {
		window->draw(*(vectofButtons[k]));
	}
}

Menus::SelectionMenu::SelectionMenu(sf::Vector2f size, sf::Vector2f pos, MenuHandler* ref) : Menu (size,pos,ref)
{
	setTexture(textmanager->getSelectionMenu());
	ButtonFirst* firstb = new ButtonFirst(sf::Vector2f(200, 200), sf::Vector2f(400, 400),this);
	ButtonSecond* secondb = new ButtonSecond(sf::Vector2f(200, 200), sf::Vector2f(700, 400), this);
	firstb->startRed();
	add(firstb);
	add(secondb);
}

Menus::SelectionMenu::~SelectionMenu() {
	for (int k = 0; k < vectofButtons.size(); k++) {
		delete vectofButtons[k];
	}
}

void Menus::SelectionMenu::function(float deltat)
{
	selector(deltat);
	drawMenu(getMHRef()->getWindow());
}

void Menus::SelectionMenu::drawMenu(sf::RenderWindow* window)
{
	window->draw(*this);
	for (int k = 0; k < vectofButtons.size(); k++) {
		window->draw(*(vectofButtons[k]));
	}
}
