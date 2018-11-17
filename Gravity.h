#pragma once

#ifndef IRO_IN_THE_DARK_CHAMBER_GRAVITY_H
#define IRO_IN_THE_DARK_CHAMBER_GRAVITY_H
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;

class Gravity {
public:
	void considerGravity(Sprite &Obj);

private:
	const float gSpeed = 7;
};

#endif // !IRO_IN_THE_DARK_CHAMBER_GRAVITY_H

