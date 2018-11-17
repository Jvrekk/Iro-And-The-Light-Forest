#pragma once

#ifndef IRO_IN_THE_DARK_CHAMBER_JETPACK_H
#define IRO_IN_THE_DARK_CHAMBER_JETPACK_H
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;

class JetPack {
public:
	void Fly(Sprite &Obj);

private:
	bool jumpAble;
	float flySpeed = 15;
	float fuel = 150;
	float fuelMax = 150;
	float fuelLoss = 2;
	float fuelUsage = 1;
};

#endif // !IRO_IN_THE_DARK_CHAMBER_JETPACK_H

