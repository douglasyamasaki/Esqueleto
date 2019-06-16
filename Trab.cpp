#include <SFML/Graphics.hpp>
#include "Player.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
	sf::Texture tuxtext;
	tuxtext.loadFromFile("tux.png");
	Player atum(sf::Vector2f(100, 100), sf::Vector2f(50, 50), &tuxtext , sf::Vector2u(3, 9), 0.1,sf::Vector2f(100.0f,0.0f));
	float deltat = 0;
	sf::Clock clock;
	while (window.isOpen())
	{
		deltat = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		atum.Update(deltat);
		window.clear();
		window.draw(atum);
		window.display();
	}

	return 0;
}