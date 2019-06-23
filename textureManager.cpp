#include "textureManager.h"
textureManager* textureManager::instance = 0;

textureManager*  textureManager::getInstance() {
	if (!instance)
		instance = new textureManager();
	return instance;
}



textureManager::textureManager() {
	Pattack01.loadFromFile("Attack01.png");
	Pattack02.loadFromFile("Attack02.png");
	Pattack03.loadFromFile("Attack03.png");
	Pdie.loadFromFile("Die.png");
	Pjumpdown.loadFromFile("Jump Down.png");
	Pjumpup.loadFromFile("Jump Up.png");
	Pidle.loadFromFile("Idle.png");
	Pwalk.loadFromFile("Walk.png");
	Prise.loadFromFile("Rise.png");

	Arrow.loadFromFile("Arrow.png");

	p1.loadFromFile("1p.png");
	p2.loadFromFile("2p.png");
	load.loadFromFile("load.png");
	ranking.loadFromFile("highscore.png");
	first.loadFromFile("frist.png");
	second.loadFromFile("second.png");
	quit.loadFromFile("quit.png");

	mainmenu.loadFromFile("fodase.png");
	rankingmenu.loadFromFile("rank.png");
	pausemenu.loadFromFile("pause.png");
	selectionmenu.loadFromFile("select.png");
}


