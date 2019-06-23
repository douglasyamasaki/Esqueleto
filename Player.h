#pragma once
#include "AbstractEntitys.h"
#include "Collision.h"
#include "textureManager.h"
using namespace AbstractEntitys;
class Player :
	public DynamicEntity
{
public:
	Player(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture, sf::Vector2u imgCounter, float times, sf::Vector2f speed, sf::Vector2f deslocamento, sf::Vector2f hitboxArea);
	void Update(float deltat);
	void OnCollision(sf::Vector2f direction);
	void setTextures();
	const int getVidas() { return vidas; }
	const bool getInvulneravel() { return invulneravel; }
	void setVelocity(sf::Vector2f velocity) { this->velocity = velocity; }
	const sf::Vector2f getVelocity() { return velocity; }
	const sf::Vector2f getSpeed() { return speed; }
	const bool getcanJump() { return canJump; }
	const float getJumpHeight() { return jumpHeight; }
	void setcanJump(const bool opt) { canJump = opt; }
	void setFaceRight(const bool opt) { faceRight = opt; }
	void attack1();
	void attack2();
	void movement(sf::Vector2f mov);
	void die();
private:
	textureManager* textManager;
	bool canJump;
	float jumpHeight;
	sf::Vector2f speed;
	sf::Vector2f velocity;
	bool faceRight;
	int vidas;
	bool invulneravel;
};

