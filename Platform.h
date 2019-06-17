#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"
class Platform : public Collision
{
public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f pos);

	void draw(sf::RenderWindow& window) { window.draw(body); }
private:
	sf::RectangleShape body;
};

