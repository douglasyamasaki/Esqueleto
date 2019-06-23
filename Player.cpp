#include "Player.h"

Player::Player(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture, sf::Vector2u imgCounter, float times, sf::Vector2f speed,sf::Vector2f deslocamento, sf::Vector2f hitboxArea) :
	DynamicEntity(size, pos, texture, imgCounter, times,deslocamento,hitboxArea)
{
	textManager = textureManager::getInstance();
	this->speed = speed;
	faceRight = true;
	canJump = true;
	jumpHeight = 300;
}

void Player::Update(float deltat)
{
	velocity.y += 981.0f * deltat;
	UpdateA(deltat, faceRight);
	setTextureRect(getuvRect());
	moveHB(velocity.x * deltat, velocity.y * deltat);
	setPosition(hitbox.getPosition() - deslocamento);
	setTextures();
	velocity.x *= 0;
}

void Player::OnCollision(sf::Vector2f direction) {

	if (direction.x < 0.0f) {
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f) {
		velocity.x = 0;
	}
	if (direction.y < 0.0f) {
		velocity.y = 0;
		canJump = true;
	}
	else if (direction.y > 0.0f) {
		velocity.y = 0;
	}
}

void Player::setTextures()
{
	if (!getLock()){
	if (velocity.y > 0.0f && !canJump)
		setTexture(textManager->getJumpup());
	else if (velocity.y < 0.0f)
		setTexture(textManager->getJumpdown());
	else if ((velocity.x > 0.0f || velocity.x < 0.0f) && !getLock())
		setTexture(textManager->getWalk());
	else if (velocity.x == 0.0f && !getLock())
	setTexture(textManager->getIdle());
	}
}

void Player::attack1()
{
	if (!getLock()){
	setLock();
	resetAll();
	setTexture(textManager->getAttack01());
	}
}

void Player::movement(sf::Vector2f mov)
{
	if (!getLock()){
	if (mov.x < 0) {
		faceRight = false;
		velocity.x -= speed.x;
	}
	if (mov.x > 0) {
		faceRight = true;
		velocity.x += speed.x;
	}
	if (mov.y > 0 && canJump){
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
		canJump = false;
	}
	}
}
