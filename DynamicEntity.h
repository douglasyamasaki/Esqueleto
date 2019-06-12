#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Animation.h"
class DynamicEntity : public Entity , public Animation
{
public:
	DynamicEntity(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture, sf::Vector2u imgCounter, float times);
};

