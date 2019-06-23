#pragma once
#include "Lists.h"

using namespace Lists;
class textureManager;
class Menu;
class Player;
class MenuHandler;
class Controlador;
namespace Levels{
	class Level
	{
	public:
		virtual void UpdateLevel(sf::RenderWindow* window, float deltat) = 0;
		virtual void LoadFixed() = 0;
		textureManager* textManager;
		//virtual void LoadStandard() = 0;
		Level(MenuHandler* menuref);
		Player* getP1() { return P1; }
		Player* getP2() { return P2; }
		void setP1(Player* P1) { this->P1 = P1; }
		void setP2(Player* P2) { this->P2 = P2; }
		Controlador* controller;
	protected:
		Player* P1;
		Player* P2;
		StaticEntity* pl1;
		MenuHandler* menuref;
		DynamicList* DynList;
		StaticList* StList;
		EntityList* ScenaryList;
	};

	class FirstLevel : public Level {
	private:
	public:
		void UpdateLevel(sf::RenderWindow* window, float deltat);
		void LoadFixed();
		FirstLevel(MenuHandler* menuref);
		~FirstLevel() { StList->~StaticList(); }
	};
}