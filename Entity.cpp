#include "Entity.h"



Entity::Entity(const sf::Vector2f size, const sf::Vector2f pos, sf::Texture * texture) : sf::RectangleShape(size)
{
	this->setPosition(pos);
	this->setTexture(texture);
}

Entity::~Entity()
{
}
