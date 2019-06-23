#pragma once
#include "Collision.h"
#include "Animation.h"
#include <SFML/Graphics.hpp>
namespace AbstractEntitys {
	class Entity : public sf::RectangleShape
	{
	private:
	public:
		Entity(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture);
	};
	
	class StaticEntity :
		public Entity,
		public Collision
	{
	public:
		StaticEntity(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture, sf::Vector2f deslocamento, sf::Vector2f hitboxArea);
		//~StaticEntity();
	};

	class DynamicEntity : public Entity, public Animation, public Collision
	{
	protected:
		sf::Vector2f deslocamento;
	public:
		DynamicEntity(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture, sf::Vector2u imgCounter, float times, sf::Vector2f deslocamento, sf::Vector2f hitboxArea);
		virtual void Update(float deltat) = 0;
	};


}