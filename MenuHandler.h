#pragma once
#include "Menus.h"
#include "Level.h"
using namespace Levels;
using namespace Menus;
class MenuHandler
{
private:
	bool p2;
	Menu* currentMenu;
	Level* currentLevel;
	sf::RenderWindow* window;
	sf::View* view;
	PauseMenu pauseobj;
	RankingMenu rankingobj;
	MainMenu mainobj;
	SelectionMenu selectionobj;
	bool active;
public:
	void setView(sf::View* view) {this->view = view;}
	sf::View* getView() { return view; }
	const bool getP2() { return p2; }
	void setWindow(sf::RenderWindow* window) { this->window = window; }
	void execute(float deltat) { currentMenu->function(deltat); }
	void setP2(const bool opt) { p2 = opt; }
	void setLevel(Level* newLevel) { this->currentLevel = newLevel; }
	Level* getLevel() { return currentLevel; }
	const bool getActive() { return active; }
	sf::RenderWindow* getWindow() { return window; }
	void setActive(const bool opt) { active = opt; }
	void switchtoSelection() { currentMenu = &selectionobj; }
	void switchtoMain() { currentMenu = &mainobj; }
	void switchtoPause() { currentMenu = &pauseobj; };
	void switchtoRanking() { currentMenu = &rankingobj; }
	bool load() { return true; }
	MenuHandler();
	~MenuHandler();
};

