#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "JetPack.h"

using namespace sf;
using namespace std;

void JetPack::Fly(Sprite &Obj) {
	fuel += fuelLoss;

	if (fuel > fuelMax) fuel = fuelMax;
	if (fuel < 0) fuel = 0;

	if (Keyboard::isKeyPressed(Keyboard::W)) {

		if (jumpAble) {
			fuelLoss = -fuelUsage * 3;
			Obj.move(0, -flySpeed);
			if (fuel <= 1)
				jumpAble = false;
		}
		else {
			fuel += fuelUsage;
			if (fuel >= fuelMax / 2)
				jumpAble = true;
		}
	}
	else {
		fuelLoss = fuelUsage;
	}
}

