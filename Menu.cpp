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
	window.clear(Color(200, 140, 200));

	sf::Font font;
	if (!font.loadFromFile("startPage.ttf"))
	{
		std::cout << "startPage ttf load fail";
	}

	sf::Text play;
	sf::Text quit;

	// select the font
	play.setFont(font); // font is a sf::Font

						// set the string to display
	play.setString("Play");
	// set the character size
	play.setCharacterSize(72); // in pixels, not points!

							   // set the color
	play.setFillColor(sf::Color::Black);



	if (Keyboard::isKeyPressed(Keyboard::Return)) {
		this->menu = false;
		this->play = true;
	}

	// set the text style
	window.draw(play);
	window.display();
}


void Menu::drawStartingPage(RenderWindow & window)
{
	window.clear(Color(200, 140, 200));

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
	welcome.setFillColor(sf::Color::Black);

	goForward.setFont(font);
	goForward.setPosition(Settings::windowWidth / 2 - 320, Settings::windowHeight / 2 - 100);
	goForward.setString("Press sprace to continue...");
	goForward.setCharacterSize(32);
	goForward.setFillColor(sf::Color::Black);


	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		this->startingPage = false;
		this->menu = true;
	}

	// set the text style
	window.draw(welcome);
	window.draw(goForward);
	window.display();
}
	