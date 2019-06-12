#include "Entity.h"

Entity::Entity(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture) : sf::RectangleShape(size)
{
	this->setPosition(pos);
	this->setTexture(texture);
}
