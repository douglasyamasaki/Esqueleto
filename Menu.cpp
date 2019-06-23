#include "Menu.h"
#include "textureManager.h"
Menu::Menu(sf::Vector2f size, sf::Vector2f pos, MenuHandler* MHref) : RectangleShape (size)
{
	textmanager = textureManager::getInstance();
	setPosition(pos);
	i = 0;
	this->MHref = MHref;
	timet = 0;
	times = 0.1;
}

void Menu::select() {
	vectofButtons[i]->selected();

}
void Menu::selector(float deltat)
{
	timet += deltat;
	if (timet >= times){
		timet -= times;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			if (i > 0) {
				vectofButtons[i]->setFillColor(sf::Color::White);
				i--;
				vectofButtons[i]->setFillColor(sf::Color::Red);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (i < vectofButtons.size() -1) {
				vectofButtons[i]->setFillColor(sf::Color::White);
				i++;
				vectofButtons[i]->setFillColor(sf::Color::Red);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (i >= 0 && i < vectofButtons.size())
				select();
		}
	}
}
