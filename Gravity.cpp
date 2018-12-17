#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Gravity.h"

using namespace sf;
using namespace std;

void Gravity::considerGravity(Sprite &Obj) {
	Obj.move(0, gSpeed);
};

