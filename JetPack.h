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
	float flySpeed = 3;
	float fuel = 500;
	float fuelMax = 500;
	float fuelLoss = 0.5;
	float fuelUsage = 0.2;
};

#endif // !IRO_IN_THE_DARK_CHAMBER_JETPACK_H

