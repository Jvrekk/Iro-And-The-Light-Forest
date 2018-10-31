#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "player.h"
using namespace sf;
using namespace std;

// ta klasa musi byc odziedziczona przez inna klase ktora musi nadpisac ta metode considerGravity i wywolac w 
// niej metode nadrzedna przez uzycie "Gravity::" z wyslaniem siebie patrz player.h considerGravity
// takie tam proste wytlumaczenie xD
class Gravity {
public:

	template <class T> void considerGravity(T &Obj) {
		Obj.move(0, gSpeed);
	};


	/* nie wiem czemu nie dzala

	template <class T> void considerGravity(T *Obj) {
		
		if (isFalling) {
			Obj.move(0, gSpeed);
			cout << Obj.getPosition().y << endl;
		}
		else if (Obj.getPosition().y >= 200) {
			Obj.setPosition(0, 0);
		}
	};	*/

	 float gSpeed = 0.4;
	 bool isFalling = true;
};