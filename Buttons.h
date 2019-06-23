#pragma once
#include "MenuButton.h"
namespace Buttons {
	class Button1p : public MenuButton {
	private:
	public:
		Button1p(sf::Vector2f size, sf::Vector2f pos, Menu* refe);
		void selected();
	};

	class Button2p : public MenuButton {
	private:
	public:
		Button2p(sf::Vector2f size, sf::Vector2f pos, Menu* refe);
		void selected();
	};

	class ButtonResume : public MenuButton {
	private:
	public:
		ButtonResume(sf::Vector2f size, sf::Vector2f pos, Menu* refe);
		void selected();
	};

	class ButtonHighscore : public MenuButton {
	private:
	public:
		ButtonHighscore(sf::Vector2f size, sf::Vector2f pos, Menu* refe);
		void selected();
	};

	class ButtonLoad : public MenuButton {
	private:
	public:
		ButtonLoad(sf::Vector2f size, sf::Vector2f pos, Menu* refe);
		void selected();
	};

	class ButtonQuit : public MenuButton {
	private:
	public:
		ButtonQuit(sf::Vector2f size, sf::Vector2f pos, Menu* refe);
		void selected();
	};
	
	class ButtonReturn : public MenuButton {
	private:
	public:
		ButtonReturn(sf::Vector2f size, sf::Vector2f pos, Menu* refe);
		void selected();
		 };

	class ButtonSave : public MenuButton {
	private:
	public:
		ButtonSave(sf::Vector2f size, sf::Vector2f pos, Menu* refe);
		void selected();
	};

	class ButtonFirst : public MenuButton {
	private:
	public:
		ButtonFirst(sf::Vector2f size, sf::Vector2f pos, Menu* refe);
		void selected();
	};

	class ButtonSecond : public MenuButton {
	private:
	public:
		ButtonSecond(sf::Vector2f size, sf::Vector2f pos, Menu* refe);
		void selected();
	};
	}
