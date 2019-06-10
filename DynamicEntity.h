#pragma once
#include "Entity.h"
#include "Animator.h"
class DynamicEntity : public Entity , public Animator
{
private:
	sf::Vector2f vel;
	sf::Vector2f acel;
public:
	DynamicEntity(sf::Vector2f size , sf::Vector2f pos , sf::Texture* texture);
	~DynamicEntity();
	const sf::Vector2f getVel() { return vel; }
	const sf::Vector2f getAcel() { return acel;  }
	virtual void update();

};

