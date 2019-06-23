#include "AbstractEntitys.h"

AbstractEntitys::Entity::Entity(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture) : 
	sf::RectangleShape(size)
{
	this->setPosition(pos);
	this->setOrigin(size / 2.0f);
	this->setTexture(texture);
}


AbstractEntitys::StaticEntity::StaticEntity(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture, sf::Vector2f deslocamento, sf::Vector2f hitboxArea) : 
	Entity(size, pos, texture), 
	Collision(size)
{
	hitbox.setFillColor(sf::Color::Green);
	hitbox.setPosition(pos);
	hitbox.setOrigin(size / 2.0f);
}

AbstractEntitys::DynamicEntity::DynamicEntity(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture, sf::Vector2u imgCounter, float times, sf::Vector2f deslocamento, sf::Vector2f hitboxArea) :
	Entity(size, pos, texture),
	Animation(texture, imgCounter, times),
	Collision(hitboxArea)
{
	this->deslocamento = deslocamento;
	hitbox.setFillColor(sf::Color::Blue);
	hitbox.setOrigin(hitboxArea / 2.0f);
	hitbox.setPosition(pos += deslocamento);
}
