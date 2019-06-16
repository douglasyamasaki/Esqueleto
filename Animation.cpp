#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imgCounter, float times)
{
	this->times = times;
	this->imgCounter = imgCounter;
	timet = 0;
	imgCurrent.x = 0;
	uvRect.width = texture->getSize().x / float(imgCounter.x);
	uvRect.height = texture->getSize().y / float(imgCounter.y);
}

void Animation::UpdateA(int row, float deltat, bool faceright)
{
	imgCurrent.y = row;
	timet += deltat;
	if (timet >= times) {
		timet -= times;
		imgCurrent.x++;
		if (imgCurrent.x >= imgCounter.x) {
			imgCurrent.x = 0;
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
	
}
