#include "DynamicEntity.h"

DynamicEntity::DynamicEntity(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture, sf::Vector2u imgCounter, float times, sf::Vector2f deslocamento, sf::Vector2f hitboxArea) : 
	Entity(size, pos, texture), 
	Animation(texture, imgCounter, times), 
	Collision (hitboxArea)
{
	this->deslocamento = deslocamento;
	hitbox.setFillColor(sf::Color::Blue);
	hitbox.setOrigin(hitboxArea / 2.0f);
	hitbox.setPosition(pos += deslocamento);
}
