#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
private:
	sf::Vector2u imgCounter;
	sf::Vector2u imgCurrent;
	float timet;
	float times;
	sf::IntRect uvRect;
public:
	Animation(sf::Texture* texture,sf::Vector2u imgCounter,float times);
	void UpdateA(int row, float deltat, bool faceright);
	const sf::IntRect getuvRect() { return uvRect; }
	void setuvRect(const sf::IntRect uvRect) { this->uvRect = uvRect; }
};

