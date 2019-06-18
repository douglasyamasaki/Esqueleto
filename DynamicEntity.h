#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Animation.h"
#include "Collision.h"
class DynamicEntity : public Entity , public Animation , public Collision
{
protected:
	sf::Vector2f deslocamento;
public:
	DynamicEntity(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture, sf::Vector2u imgCounter, float times, sf::Vector2f deslocamento, sf::Vector2f hitboxArea);
};

