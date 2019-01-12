#pragma once

#ifndef IRO_IN_THE_DARK_CHAMBER_SETTINGS_H
#define IRO_IN_THE_DARK_CHAMBER_SETTINGS_H
#include <cstdlib>
#include <iostream>
using namespace std;
/*!
*! @brief Settings klasa opisuj¹ca opcje okna takie jak szerokosc wysokosc
*! @param Settings::windowWidth	okresla szerokosc okna
*! @param Settings::windowHeight okresla wysokosc okna
*! @param Settings::FPS okresla ilosc klatek na sekunde
*! @param Settings::Gravity okresla predosc grawitacji
*/
class Settings {
public:
	static int windowWidth;
	static int windowHeight;
	static int FPS;
	static float Gravity;
};

#endif // !IRO_IN_THE_DARK_CHAMBER_SETTINGS_H

