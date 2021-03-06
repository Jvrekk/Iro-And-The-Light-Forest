#include "Menu.h"
#include "Settings.h"
#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
Menu::Menu()
{
	 isRuning = true;
	 startingPage = true;
	 menu = false;
	 play = false;
	 quit = false;
}

void Menu::drawMenu(RenderWindow & window)
{
	window.clear(Color(33, 0, 7));

	sf::Font font;
	if (!font.loadFromFile("startPage.ttf"))
	{
		std::cout << "startPage ttf load fail";
	}

	sf::Text play;
	sf::Text goForward;
	sf::Text quit;

	play.setFont(font);
	play.setPosition(Settings::windowWidth / 2 - 160, Settings::windowHeight / 2 - 200);
	play.setString("Play");
	play.setCharacterSize(72);
	play.setFillColor(sf::Color::White);

	goForward.setFont(font);
	goForward.setPosition(Settings::windowWidth / 2 - 185, Settings::windowHeight / 2 - 100);
	goForward.setString("Press enter to continue...");
	goForward.setCharacterSize(16);
	goForward.setFillColor(sf::Color::White);


	quit.setFont(font);
	quit.setPosition(Settings::windowWidth / 2 - 160, Settings::windowHeight / 2 - 60);
	quit.setString(" Quit - ESC");
	quit.setCharacterSize(32);
	quit.setFillColor(sf::Color::White);


	if (Keyboard::isKeyPressed(Keyboard::Return)) {
		this->menu = false;
		this->play = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		this->menu = false;
		this->play = false;
		this->isRuning = false;
	}

	// set the text style
	window.draw(play);
	window.draw(goForward);
	window.draw(quit);
	window.display();
}


void Menu::drawStartingPage(RenderWindow & window)
{
	window.clear(Color(33, 0, 7));

	sf::Font font;
	if (!font.loadFromFile("startPage.ttf"))
	{
		std::cout << "startPage ttf load fail";
	}

	sf::Text welcome;
	sf::Text goForward;
	sf::Text quit;

	
	welcome.setFont(font); 
	welcome.setPosition(Settings::windowWidth / 2 - 520, Settings::windowHeight / 2 - 200);
	welcome.setString("Iro In The Dark Chamber");
	welcome.setCharacterSize(72);
	welcome.setFillColor(sf::Color::White);

	goForward.setFont(font);
	goForward.setPosition(Settings::windowWidth / 2 - 320, Settings::windowHeight / 2 - 100);
	goForward.setString("Press sprace to continue...");
	goForward.setCharacterSize(32);
	goForward.setFillColor(sf::Color::White);


	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		this->startingPage = false;
		this->menu = true;
	}

	// set the text style
	window.draw(welcome);
	window.draw(goForward);
	window.display();
}
	