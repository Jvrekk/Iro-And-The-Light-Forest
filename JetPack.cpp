#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "JetPack.h"

using namespace sf;
using namespace std;
JetPack::JetPack() {

}
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

void JetPack::draw(RenderWindow &window,float xmove) {

	fuelMaxBar.setSize(Vector2f(fuelMax * 2, 40));
	fuelMaxBar.setPosition(Vector2f(30+xmove, 620));
	fuelMaxBar.setFillColor(sf::Color(135, 135, 135));
	fuelActual.setSize(Vector2f(fuel * 2, 40));
	fuelActual.setPosition(Vector2f(30 + xmove, 620));
	fuelActual.setFillColor(sf::Color(150, 0, 0));
	fuelActual.setSize(Vector2f(fuel*2, 40));

	window.draw(fuelMaxBar);
	window.draw(fuelActual);
}

