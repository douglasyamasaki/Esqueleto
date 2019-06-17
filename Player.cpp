#include "Player.h"

Player::Player(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture, sf::Vector2u imgCounter, float times, sf::Vector2f speed,sf::Vector2f deslocamento, sf::Vector2f hitboxArea) :
	DynamicEntity(size, pos, texture, imgCounter, times,deslocamento,hitboxArea)
{
	this->speed = speed;
	row = 0;
	faceRight = true;
}

void Player::Update(float deltat)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed.x * deltat;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed.x * deltat;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		movement.y -= speed.x * deltat;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += speed.x * deltat;

	if (movement.x == 0)
		row = 0;
	else{
		row = 1;

		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	UpdateA(row, deltat, faceRight);
	setTextureRect(getuvRect());
	if (!blocked){
	move(movement);
	moveHB(movement.x, movement.y);
	}

}
