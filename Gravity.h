#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#ifndef IRO_IN_THE_DARK_CHAMBER_GRAVITY_H
#define IRO_IN_THE_DARK_CHAMBER_GRAVITY_H


using namespace sf;
using namespace std;

class Gravity {
public:
	template <class T> void considerGravity(T &Obj);

private:
	float gSpeed = 0.4;
};

#endif // !IRO_IN_THE_DARK_CHAMBER_GRAVITY_H

