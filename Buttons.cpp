#include "Buttons.h"
#include "Menu.h"
#include "textureManager.h"
#include "MenuHandler.h"
#include "Level.h"
using namespace Levels;
Buttons::Button1p::Button1p(sf::Vector2f size, sf::Vector2f pos, Menu* refe) : MenuButton(size,pos,refe)
{
	setTexture(textManager->getP1());
}

void Buttons::Button1p::selected()
{
	getMref()->getMHRef()->setP2(false);
	getMref()->getMHRef()->switchtoSelection();
}

Buttons::Button2p::Button2p(sf::Vector2f size, sf::Vector2f pos, Menu* refe) : MenuButton (size,pos,refe)
{
	setTexture(textManager->getP2());
}

void Buttons::Button2p::selected()
{
	Mref->getMHRef()->setP2(true);
	Mref->getMHRef()->switchtoSelection();
}

Buttons::ButtonResume::ButtonResume(sf::Vector2f size, sf::Vector2f pos, Menu* refe) : MenuButton (size,pos,refe)
{
	setTexture(textManager->getResume());
}

void Buttons::ButtonResume::selected()
{
	Mref->getMHRef()->setActive(false);
	Mref->getMHRef()->switchtoPause();
}

Buttons::ButtonHighscore::ButtonHighscore(sf::Vector2f size, sf::Vector2f pos, Menu* refe) : MenuButton(size,pos,refe)
{
	setTexture(textManager->getRanking());
}

void Buttons::ButtonHighscore::selected()
{
	Mref->getMHRef()->switchtoRanking();
}

Buttons::ButtonLoad::ButtonLoad(sf::Vector2f size, sf::Vector2f pos, Menu* refe) : MenuButton (size,pos,refe)
{
	setTexture(textManager->getLoad());
}

void Buttons::ButtonLoad::selected()
{
	Mref->getMHRef()->setActive(false);
	Mref->getMHRef()->load();
}

Buttons::ButtonQuit::ButtonQuit(sf::Vector2f size, sf::Vector2f pos, Menu* refe) : MenuButton (size,pos,refe)
{
	setTexture(textManager->getQuit());
}

void Buttons::ButtonQuit::selected()
{
	Mref->getMHRef()->getWindow()->close();
}


Buttons::ButtonReturn::ButtonReturn(sf::Vector2f size, sf::Vector2f pos, Menu* refe) : MenuButton(size, pos, refe) {
	setTexture(textManager->getReturnb());
}

void Buttons::ButtonReturn::selected() {
	Mref->getMHRef()->switchtoMain();
}

Buttons::ButtonSave::ButtonSave(sf::Vector2f size, sf::Vector2f pos, Menu* refe) : MenuButton(size,pos,refe)
{
	setTexture(textManager->getSave());
}

void Buttons::ButtonSave::selected()
{
	// save things..
	return;
}

Buttons::ButtonFirst::ButtonFirst(sf::Vector2f size, sf::Vector2f pos, Menu* refe) : MenuButton (size,pos,refe)
{;
	setTexture(textManager->getFirst());
}

void Buttons::ButtonFirst::selected()
{
	FirstLevel* lvl = new FirstLevel(Mref->getMHRef());
	lvl->LoadFixed();
	Mref->getMHRef()->setActive(false);
	Mref->getMHRef()->setLevel(lvl);
	return;
}

Buttons::ButtonSecond::ButtonSecond(sf::Vector2f size, sf::Vector2f pos, Menu* refe) : MenuButton (size,pos,refe)
{
	setTexture(textManager->getSecond());
}

void Buttons::ButtonSecond::selected()
{
	return;
}
