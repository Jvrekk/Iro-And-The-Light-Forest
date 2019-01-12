#pragma once

#ifndef IRO_IN_THE_DARK_CHAMBER_GRAVITY_H
#define IRO_IN_THE_DARK_CHAMBER_GRAVITY_H
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Settings.h"
using namespace sf;
using namespace std;
/*!
*! @brief Gravity klasa opisuj¹ca grawitacje w rozgrywce
*
*! @param Gravity::gSpeed podstawowa wielkoœæ prêdkoœci "przyci¹gania"
*! @param Gravity::gSpeedMin minimalna prêdkoœæ "przyci¹gania"
*! @param Gravity::gVelocity prêdkoœæ przyœpieszania
*/
class Gravity {
public:
	/*!
	*! @brief considerGravity funkcja uwzglednia przekazany sprite do grawitacji
	*
	*! @param Sprite &Obj to element ktory ma opadac pod wplywem grawitacji
	*/
	void considerGravity(Sprite &Obj);

private:
	float gSpeed = Settings::Gravity;
	float gSpeedMin = 4;
	float gVelocity = 0.2;
};

#endif // !IRO_IN_THE_DARK_CHAMBER_GRAVITY_H

