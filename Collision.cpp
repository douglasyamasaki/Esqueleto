#include "Collision.h"

Collision::Collision(sf::Vector2f hitboxSize)
{
	hitbox.setSize(hitboxSize);
}

bool Collision::checkCollision(Collision* other, float push)
{
	sf::Vector2f otherPos = other->getPos();
	sf::Vector2f otherHs = other->getHS();
	sf::Vector2f thisPos = getPos();
	sf::Vector2f thisHs = getHS();

	float deltaX = otherPos.x - thisPos.x;
	float deltaY = otherPos.y - thisPos.y;
	float interX = abs(deltaX) - (otherHs.x + thisHs.x);
	float interY = abs(deltaY) - (otherHs.y + thisHs.y);

	if (interX < 0.0f && interY < 0.0f) {

		push = std::min(std::max(push, 0.0f), 1.0f);

		if (interX > interY) {
			if (deltaX > 0.0f){
				moveHB(interX * (1.0f - push), 0.0f);
				other->moveHB(-interX * push, 0.0f);
			}
			else {
				moveHB(-interX * (1.0f - push), 0.0f);
				other->moveHB(-interX * push, 0.0f);
			}
		}
		else {
			if (deltaY > 0.0f) {
				moveHB(0.0f, interY * (1.0f - push));
				other->moveHB(0.0f, -interY * push);
			}
			else {
				moveHB(0.0f, -interY * (1.0f - push));
				other->moveHB(0.0f ,-interY * push);
			}
		}
		return true;
	}
	return false;
}
