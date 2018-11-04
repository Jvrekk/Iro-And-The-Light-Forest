#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Gravity.h"
using namespace sf;
using namespace std;

	//TODO ENCHANCED GRAVITY EXPERIENCE VIA VELOCITY
	template <class T> void Gravity::considerGravity(T &Obj) {
		Obj.move(0, gSpeed);
	};


	