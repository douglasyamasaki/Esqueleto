#include "Lists.h"
void Lists::EntityList::drawAll(sf::RenderWindow* window)
{
	for (it = ListofEntitys.getFirst(); it != ListofEntitys.getLast(); it++) {
		window->draw(*(it.getInfo()->getData()));
	}

}



void Lists::StaticList::drawAll(sf::RenderWindow* window)
{
	for (it = ListofStatics.getFirst(); it != nullptr; it++) {
		window->draw(*(it.getInfo()->getData()));
	}
}

void Lists::DynamicList::drawAll(sf::RenderWindow* window)
{
	for (it = ListofDinamics.getFirst(); it != nullptr; it++) {
		window->draw(*(it.getInfo()->getData()));
	}
}

