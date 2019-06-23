#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imgCounter, float times)
{
	this->times = times;
	this->imgCounter = imgCounter;
	timet = 0;
	imgCurrent.x = 0;
	imgCurrent.y = 0;
	cont = 0;
	lock = false;
	uvRect.width = texture->getSize().x / float(imgCounter.x);
	uvRect.height = texture->getSize().y / float(imgCounter.y);
}

bool Animation::UpdateA(float deltat, bool faceright)
{
	
	timet += deltat;
	if (timet >= times) {
		timet -= times;
		imgCurrent.x++;
		this->cont++;

		if (imgCurrent.x >= imgCounter.x) {
			imgCurrent.x = 0;
			imgCurrent.y++;
			this->cont++;
			if (imgCurrent.y >= imgCounter.y) {
				imgCurrent.y = 0;
				lock = false;
				cont = 0;
			}
		}
	}
	if (faceright){
		uvRect.left = imgCurrent.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else{
		uvRect.left = (imgCurrent.x +1 )* abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
	uvRect.top = imgCurrent.y * uvRect.height;
	return this->lock;
}
