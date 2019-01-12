#pragma once

#ifndef IRO_IN_THE_DARK_CHAMBER_MOUSEDIRECTIONS_H
#define IRO_IN_THE_DARK_CHAMBER_MOUSEDIRECTIONS_H
#include <cstdlib>
#include <math.h>
#include <vector>
#include <iostream>
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include <SFML\Graphics.hpp>


using namespace sf;
/*!
*! @brief MouseDirections klasa umozliwia obliczanie kierunku lotu pociskow i kat myszki wzgledem postaci
*
*! @param MouseDirections::centrePlayerPos zmienna przechowujaca centralna pozycje player'a
*! @param MouseDirections::currentPlayerPos zmienna przechowujaca obecna centralna pozycje player'a
*! @param MouseDirections::mCurrentPos zmienna przechowujaca obecna centralna pozycje kursora
*! @param MouseDirections::mTargetDir zmienna przechowujaca kierunek kursora
*! @param MouseDirections::angle zmienna przechowujaca kat miedzy mysza a playerem
*/
class MouseDirections{

public:
	/*!
	*! @brief mouseDirections funkcja oblicza kierunek lotu pociskow
	*! @param widnow to wskaznik na zmienna typu RenderWindow
	*! @param widnow to sprite playera
	*! @return Vector2f zwraca Vektor2f ktory jest kierunkiem w ktorym beda leciec pociski
	*/
	Vector2f mouseDirections(RenderWindow &window, Sprite player,float xmove);
	/*!
	*! @brief getRotation funkcja oblicza kat pomiedzy playerem a mysza
	*! @param widnow to wskaznik na zmienna typu RenderWindow
	*! @param widnow to sprite playera
	*! @return float zwraca kat miedzy mysza a postacia
	*/
	float getRotation(RenderWindow &window, Sprite player,float xmove);

	
	
private:
	//m mouse dir directions pos position
	Vector2f centrePlayerPos;
	Vector2f currentPlayerPos;
	
	Vector2f mCurrentPos;
	Vector2f mTargetDir;
	Vector2f mTargetDirCalc;
	float angle;

};
#endif // !IRO_IN_THE_DARK_CHAMBER_MOUSEDIRECTIONS_H