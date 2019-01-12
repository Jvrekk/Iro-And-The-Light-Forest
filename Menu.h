#pragma once
#ifndef IRO_IN_THE_DARK_CHAMBER_MENU_H
#define IRO_IN_THE_DARK_CHAMBER_MENU_H
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "MouseDirections.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

/*!
*! @brief Menu klasa obslugujaca menu
*
*! @param Menu::isRuning zmienna typu bool okreslajaca ktory element menu ma zostac wyswietlony
*! @param Menu::menu zmienna typu bool okreslajaca ktory element menu ma zostac wyswietlony
*! @param Menu::starzmienna typu bool okreslajaca ktory element menu ma zostac wyswietlony
*! @param Menu::play zmienna typu bool okreslajaca ktory element menu ma zostac wyswietlony
*! @param Menu::quit zmienna typu bool okreslajaca ktory element menu ma zostac wyswietlony
*/
class Menu {	
public:
	Menu();
	
	bool isRuning;
	bool menu;
	bool startingPage;
	bool play;
	bool quit;
	/*!
	*! @brief drawMenu funkcja rysujaca element menu
	*
	*! @param widnow to wskaznik na zmienna typu RenderWindow
	*/
	void drawMenu(RenderWindow & window);
	/*!
	*! @brief drawStartingPage funkcja rysujaca element menu
	*
	*! @param widnow to wskaznik na zmienna typu RenderWindow
	*/
	void drawStartingPage(RenderWindow & window);
	sf::Font font;


};

#endif // !IRO_IN_THE_DARK_CHAMBER_MENU_H