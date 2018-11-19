#pragma once

#ifndef IRO_IN_THE_DARK_CHAMBER_GRAVITY_H
#define IRO_IN_THE_DARK_CHAMBER_GRAVITY_H
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Settings.h"
using namespace sf;
using namespace std;

class Gravity {
public:
	void considerGravity(Sprite &Obj);

private:
	float gSpeed = Settings::Gravity;
	float gSpeedMin = 7;
	float gVelocity = 0.2;
};

#endif // !IRO_IN_THE_DARK_CHAMBER_GRAVITY_H

