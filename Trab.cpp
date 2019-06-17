#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Collision.h"
#include "Platform.h"
#include <iostream>
using namespace std;

static const float VIEW_HEIGHT = 1000;
int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
	sf::Texture tuxtext;
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	tuxtext.loadFromFile("tux.png");
	Player atum(sf::Vector2f(100, 100), sf::Vector2f(25, 25), &tuxtext, sf::Vector2u(3, 9), 0.1, sf::Vector2f(100, 0), sf::Vector2f(0, 0), sf::Vector2f(100, 100));
	float deltat = 0;
	sf::Clock clock;
	//atum.setOrigin(atum.getSize() / 2.0f);
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));

	Platform platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 100.0f));
	while (window.isOpen())
	{
		deltat = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::Resized) {
				view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
			}
		}

		atum.Update(deltat);
		cout << atum.getPosition().x << atum.getPosition().y << atum.getHB().getPosition().x<< atum.getHB().getPosition().y << endl;
		platform1.getCol()->checkCollision(atum.getCol(),0.0f);
		view.setCenter(atum.getPosition());
		window.clear();
		window.setView(view);
		window.draw(atum);
		window.draw(atum.getCol()->getHB());
		platform1.draw(window);
		window.display();
	}

	return 0;
}