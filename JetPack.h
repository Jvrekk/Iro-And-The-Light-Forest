#pragma once

#ifndef IRO_IN_THE_DARK_CHAMBER_JETPACK_H
#define IRO_IN_THE_DARK_CHAMBER_JETPACK_H
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;
/*!
*! @brief JetPack klasa opisuj�ca opcje okna takie jak szerokosc wysokosc
*! @param Settings::windowWidth	okresla szerokosc okna
*! @param Settings::windowHeight okresla wysokosc okna
*! @param Settings::FPS okresla ilosc klatek na sekunde
*! @param Settings::Gravity okresla predosc grawitacji
*/
class JetPack {
public:
	JetPack();
	void Fly(Sprite &Obj);
	void draw(RenderWindow &window,float xmove);

private:
	bool jumpAble;
	float flySpeed = 15;
	float fuel = 150;
	float fuelMax = 150;
	float fuelLoss = 2;
	float fuelUsage = 1;
	sf::RectangleShape fuelMaxBar;
	sf::RectangleShape fuelActual;
};

#endif // !IRO_IN_THE_DARK_CHAMBER_JETPACK_H

