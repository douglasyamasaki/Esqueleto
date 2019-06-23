#include "Principal.h"
#include "textureManager.h"
Principal::Principal() : menu (){
	Executar();
}

static const float VIEW_HEIGHT = 1000;

void Principal::Executar() {
	sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");
	textureManager* txt = textureManager::getInstance();
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	float deltat = 0;
	sf::Clock clock;
	menu.setWindow(&window);
	menu.setView(&view);
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	while (window.isOpen())
	{
		deltat = clock.restart().asSeconds();
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (deltat > 1.0f / 20.0f)
				deltat = 1.0f / 20.0f;
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::Resized) {
				view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
			}
		}

		sf::Vector2f direction;
		window.clear();
		if (menu.getActive()) {
			menu.execute(deltat);
		}
		else {
			menu.getLevel()->UpdateLevel(&window,deltat);
		}
		window.setView(view);
		window.display();
	}
}