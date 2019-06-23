#include "Collision.h"

Collision::Collision(sf::Vector2f hitboxSize)
{
	hitbox.setSize(hitboxSize);
	blocked = false;
}

bool Collision::checkCollision(Collision* other, float push)
{
	sf::Vector2f otherPos = other->getHB().getPosition();
	sf::Vector2f otherHs = other->getHB().getSize()/2.0f;
	sf::Vector2f thisPos = getPos();
	sf::Vector2f thisHs = getHS();
	float deltaX = otherPos.x - thisPos.x;
	float deltaY = otherPos.y - thisPos.y;
	float interX = abs(deltaX) - (otherHs.x + thisHs.x);
	float interY = abs(deltaY) - (otherHs.y + thisHs.y);
	//printf("otx %.1f , oty %.1f , tx  %.1f, ty %.1f, ohsx %.1f, ohsy  %.1f, thsx %.1f, thsy %.1f, deltax %.1f ,deltay %.1f, interx %.1f,intery %.1f\n", otherPos.x, otherPos.y, thisPos.x, thisPos.y, otherHs.x, otherHs.y, thisHs.x, thisHs.y, deltaX, deltaY, interX, interY);
	if (interX < 0.0f && interY < 0.0f) {

		if (interX > interY) {
			if (deltaX > 0.0f){
				moveHB(interX * (1.0f - push), 0.0f);
				other->moveHB(-interX * push , 0.0f);
			}
			else {
				moveHB(-interX * (1.0f - push), 0.0f);
				other->moveHB(interX * push , 0.0f);
			}
		}
		else {
			if (deltaY > 0.0f) {
				moveHB(0.0f, interY * (1.0f - push));
				other->moveHB(0.0f, -interY * push);
			}
			else {
				moveHB(0.0f, -interY * (1.0f - push));
				other->moveHB(0.0f ,interY * push);
			}
		}
		this->blocked = true;
		return true;
	}
	this->blocked = false;
	return false;
}

bool Collision::checkCollision(Collision* other,sf::Vector2f& direction, float push)
{
	sf::Vector2f otherPos = other->getHB().getPosition();
	sf::Vector2f otherHs = other->getHB().getSize() / 2.0f;
	sf::Vector2f thisPos = getPos();
	sf::Vector2f thisHs = getHS();
	float deltaX = otherPos.x - thisPos.x;
	float deltaY = otherPos.y - thisPos.y;
	float interX = abs(deltaX) - (otherHs.x + thisHs.x);
	float interY = abs(deltaY) - (otherHs.y + thisHs.y);
	//printf("otx %.1f , oty %.1f , tx  %.1f, ty %.1f, ohsx %.1f, ohsy  %.1f, thsx %.1f, thsy %.1f, deltax %.1f ,deltay %.1f, interx %.1f,intery %.1f\n", otherPos.x, otherPos.y, thisPos.x, thisPos.y, otherHs.x, otherHs.y, thisHs.x, thisHs.y, deltaX, deltaY, interX, interY);
	if (interX < 0.0f && interY < 0.0f) {

		if (interX > interY) {
			if (deltaX > 0.0f) {
				moveHB(interX * (1.0f - push), 0.0f);
				other->moveHB(-interX * push, 0.0f);
				direction.x = 1;
				direction.y = 0;
			}
			else {
				moveHB(-interX * (1.0f - push), 0.0f);
				other->moveHB(interX * push, 0.0f);
				direction.x = -1;
				direction.y = 0;
			}
		}
		else {
			if (deltaY > 0.0f) {
				moveHB(0.0f, interY * (1.0f - push));
				other->moveHB(0.0f, -interY * push);
				direction.x = 0;
				direction.y = 1;
			}
			else {
				moveHB(0.0f, -interY * (1.0f - push));
				other->moveHB(0.0f, interY * push);
				direction.x = 0;
				direction.y = -1;
			}
		}
		this->blocked = true;
		return true;
	}
	this->blocked = false;
	return false;
}
