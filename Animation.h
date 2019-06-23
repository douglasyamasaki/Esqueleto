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
	int cont;
	bool lock;
public:
	const int getCont() { return cont; }
	const bool getLock() { return lock; }
	void setTimeS(const float times) { this->times = times; }
	void setLock() { lock = true; }
	void resetAll() { cont = 0; imgCurrent = sf::Vector2u (0,0); }
	Animation(sf::Texture* texture,sf::Vector2u imgCounter,float times);
	bool UpdateA(float deltat, bool faceright);
	const sf::IntRect getuvRect() { return uvRect; }
	void setuvRect(const sf::IntRect uvRect) { this->uvRect = uvRect; }
};

