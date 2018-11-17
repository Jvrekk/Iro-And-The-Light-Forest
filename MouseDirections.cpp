#include <cstdlib>
#include <math.h>
#include <vector>
#include <iostream>
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include <SFML\Graphics.hpp>
#include "MouseDirections.h"


using namespace sf;
using namespace std;


Vector2f MouseDirections::mouseDirections(RenderWindow &window, Sprite player) {


	centrePlayerPos = Vector2f(player.getPosition().x + (player.getGlobalBounds().width / 2), player.getPosition().y + (player.getGlobalBounds().height / 2)); // oblicza srodek playera
	mCurrentPos = Vector2f(Mouse::getPosition(window));	 // zwraca pozycje myszki
	mTargetDir = mCurrentPos - centrePlayerPos;		    // oblicza pozycje myszki od postaci nie od poczatku okna 

	mTargetDirCalc = mTargetDir / sqrt(pow(mTargetDir.x, 2) + pow(mTargetDir.y, 2)); 
	//cout << mTargetDirCalc.x << ',' << mTargetDirCalc.y << endl;
	mTargetDirCalc.x *= 40;
	mTargetDirCalc.y *= 40;
	return mTargetDirCalc;
}




float MouseDirections::getRotation(RenderWindow &window, Sprite player) {


	centrePlayerPos = Vector2f(player.getPosition().x + (player.getGlobalBounds().width / 2), player.getPosition().y + (player.getGlobalBounds().height / 2)); // oblicza srodek playera
	mCurrentPos = Vector2f(Mouse::getPosition(window));	 // zwraca pozycje myszki
	mTargetDir = mCurrentPos - centrePlayerPos;         // oblicza pozycje myszki od postaci nie od poczatku okna 
	

	const float PI = 3.14159265;

	float rotation = (atan2(mTargetDir.x, mTargetDir.y)) * 180 / PI;
	rotation -= 180;
	rotation = -rotation;
	//cout << rotation << endl;
	return rotation;
}