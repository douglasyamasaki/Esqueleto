#pragma once
#include <SFML/Graphics.hpp>
class textureManager
{
private:
	textureManager();
	static textureManager* instance;
	//player
	sf::Texture Pattack01;
	sf::Texture Pattack02;
	sf::Texture Pattack03;
	sf::Texture Pdie;
	sf::Texture Pjumpup;
	sf::Texture Pjumpdown;
	sf::Texture Prise;
	sf::Texture Pwalk;
	sf::Texture Pidle;
	sf::Texture Arrow;
	// menu buttons
	sf::Texture p1;
	sf::Texture p2;
	sf::Texture returnb;
	sf::Texture quit;
	sf::Texture first;
	sf::Texture second;
	sf::Texture resume;
	sf::Texture save;
	sf::Texture ranking;
	sf::Texture load;
	// menus
	sf::Texture pausemenu;
	sf::Texture mainmenu;
	sf::Texture rankingmenu;
	sf::Texture selectionmenu;


public:
	static textureManager* getInstance();
	//player
	sf::Texture* getDie() { return &Pdie; }
	sf::Texture* getWalk() { return &Pwalk; }
	sf::Texture* getIdle() { return &Pidle; }
	sf::Texture* getRise() { return &Prise; }
	sf::Texture* getJumpup() { return &Pjumpup; }
	sf::Texture* getJumpdown() { return &Pjumpdown; }
	sf::Texture* getAttack01() { return &Pattack01; }
	sf::Texture* getAttack02() { return &Pattack01; }
	sf::Texture* getAttack03() { return &Pattack01; }
	// menu buttons
	sf::Texture* getP1() { return &p1; }
	sf::Texture* getP2() { return &p2; }
	sf::Texture* getReturnb() { return &returnb; }
	sf::Texture* getQuit() { return &quit; }
	sf::Texture* getFirst() { return &first; }
	sf::Texture* getSecond() { return &second; }
	sf::Texture* getResume() { return &resume; }
	sf::Texture* getSave() { return &save; }
	sf::Texture* getRanking() { return &ranking; }
	sf::Texture* getLoad() { return &load; }
	// menus
	sf::Texture* getPauseMenu() { return &pausemenu; }
	sf::Texture* getMainMenu() { return &mainmenu; }
	sf::Texture* getRankingMenu() { return &rankingmenu; }
	sf::Texture* getSelectionMenu() { return &selectionmenu; }
	
	
	~textureManager();
};

