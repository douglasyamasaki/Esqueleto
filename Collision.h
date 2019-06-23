#pragma once
#include <SFML/Graphics.hpp>

class Collision
{
public:
	Collision(sf::Vector2f hitboxSize);
	
	bool checkCollision(Collision* other, float push);
	bool checkCollision(Collision* other, sf::Vector2f& direction,float push);
	sf::Vector2f getPos() { return hitbox.getPosition(); }
	sf::Vector2f getHS() { return hitbox.getSize() / 2.0f; }
	Collision* getCol() { return this; }
	void moveHB(float dx, float dy) { hitbox.move(dx, dy); }
	sf::RectangleShape getHB() { return hitbox; }
protected:
	sf::RectangleShape hitbox;
	bool blocked;
};

