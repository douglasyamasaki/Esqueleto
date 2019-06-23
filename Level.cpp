#include "Level.h"
#include "Player.h"
#include "MenuHandler.h"
#include "Controlador.h"
Levels::Level::Level(MenuHandler* menuref)
{
	this->menuref = menuref;
	textManager = textureManager::getInstance();
	controller = new Controlador(this);
}


Levels::FirstLevel::FirstLevel(MenuHandler* menuref) : Level(menuref)
{
	StList = new StaticList;
	DynList = new DynamicList;
	ScenaryList = new EntityList;

}

void Levels::FirstLevel::LoadFixed() {
	StaticEntity* plat1 = new StaticEntity(sf::Vector2f(1000, 1000), sf::Vector2f(100, 100), nullptr, sf::Vector2f(0, 0), sf::Vector2f(0, 0));
	Player* atum =  new Player(sf::Vector2f(230, 261), sf::Vector2f(-100, -200), textManager->getRise(), sf::Vector2u(6, 4), 0.05, sf::Vector2f(100, 0), sf::Vector2f(0, 10), sf::Vector2f(120, 198));
	*DynList + atum;
	*StList + plat1;
	P1 = atum;
	pl1 = plat1;
}

void Levels::FirstLevel::UpdateLevel(sf::RenderWindow* window, float deltat) {
	window->clear();
	sf::Vector2f direction;
	for (StList->it = StList->getList().getFirst() ; StList->it != nullptr; StList->it++){
		StList->it.getInfo()->getData()->getCol()->checkCollision(P1->getCol(), direction, 1.0f);
		P1->OnCollision(direction);
	}
	controller->getInput();
	for (DynList->it = DynList->getList().getFirst(); DynList->it != nullptr; DynList->it++) {
		DynList->it.getInfo()->getData()->Update(deltat);
	}
	menuref->getView()->setCenter(P1->getPosition());
	StList->drawAll(window);
	DynList->drawAll(window);
}