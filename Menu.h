#pragma once
#ifndef IRO_IN_THE_DARK_CHAMBER_MENU_H
#define IRO_IN_THE_DARK_CHAMBER_MENU_H
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "MouseDirections.h"
#include "Player.h"
#include <SFML/Graphics.hpp>


class Menu {	
public:
	Menu();
	
	bool isRuning;
	bool menu;
	bool startingPage;
	bool play;
	bool quit;

	void drawMenu(RenderWindow & window);
	void drawStartingPage(RenderWindow & window);
	sf::Font font;


};

#endif // !IRO_IN_THE_DARK_CHAMBER_MENU_H