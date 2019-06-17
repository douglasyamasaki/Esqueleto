#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f pos) :
	Collision (size)
{
	hitbox.setPosition(pos);
	hitbox.setOrigin(size / 2.0f);
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(pos);
}
