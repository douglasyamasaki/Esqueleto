#pragma once
#include "DynamicEntity.h"
class Player :
	public DynamicEntity
{
public:
	Player(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture, sf::Vector2u imgCounter, float times, sf::Vector2f speed);
	void Update(float deltat);
private:
	unsigned int row;
	sf::Vector2f speed;
	bool faceRight;
};

