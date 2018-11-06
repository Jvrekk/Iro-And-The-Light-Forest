#pragma once
#include <cstdlib>
#include <math.h>
#include <vector>
#include <iostream>
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include <SFML\Graphics.hpp>
#include "Player.h"

#ifndef IRO_IN_THE_DARK_CHAMBER_MOUSEDIRECTIONS_H
#define IRO_IN_THE_DARK_CHAMBER_MOUSEDIRECTIONS_H
////LENGTH OF VECTOR: |V| = sqrt(V.x^2 + V.y^2)
////NORMALIZE VECTOR: U = V / |V|

using namespace sf;

class MouseDirections{

public:

	Vector2f mouseDirections(RenderWindow &window, Sprite player);

	float getRotation(RenderWindow &window, Sprite player);

	
	
private:
	//m mouse dir directions pos position
	Vector2f centrePlayerPos;
	Vector2f currentPlayerPos;
	
	Vector2f mCurrentPos;
	Vector2f mTargetDir;
	Vector2f mTargetDirCalc;
	float angle;

};
#endif // !IRO_IN_THE_DARK_CHAMBER_MOUSEDIRECTIONS_H