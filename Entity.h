#pragma once
#include <SFML/Graphics.hpp>
class Entity : public sf::RectangleShape
{
private:
public:
	Entity(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture);
};

