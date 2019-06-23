#include "Controlador.h"
#include "Player.h"
Controlador::Controlador(Level* ref)
{
	p1left = sf::Keyboard::Key::A;
	p1right = sf::Keyboard::Key::D;
	p1up = sf::Keyboard::Key::W;
	p1down = sf::Keyboard::Key::S;
	p1attack1 = sf::Keyboard::Key::Q;
	p1attack2 = sf::Keyboard::Key::E;
	lvlref = ref;
	pause = sf::Keyboard::Key::P;

	p2left = sf::Keyboard::Key::Left;
	p2right = sf::Keyboard::Key::Right;
	p2up = sf::Keyboard::Key::Up;
	p2down = sf::Keyboard::Key::Down;
	p2attack1 = sf::Keyboard::Key::PageUp;
	p2attack2 = sf::Keyboard::Key::PageDown;
}

void Controlador::getInput()
{
	if (sf::Keyboard::isKeyPressed(p1right)) {
		lvlref->getP1()->movement(sf::Vector2f(1, 0));
	}
	if (sf::Keyboard::isKeyPressed(p1left)) {
		lvlref->getP1()->movement(sf::Vector2f(-1, 0));
	}

	if (sf::Keyboard::isKeyPressed(p1up) && lvlref->getP1()->getcanJump()) {
		lvlref->getP1()->movement(sf::Vector2f(0, 1));
	}
	if (sf::Keyboard::isKeyPressed(p1attack1)) {
		lvlref->getP1()->attack1();
		printf("%d\n", lvlref->getP1()->getCont());
		if (lvlref->getP1()->getCont() == 8) {

		}
	}
}
