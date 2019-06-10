#pragma once
#include <SFML/Graphics.hpp>
class Entity : public sf::RectangleShape
{
public:
	Entity(const sf::Vector2f size, const sf::Vector2f pos, sf::Texture* texture);
	~Entity();
};

