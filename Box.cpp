#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "box.h"


using namespace sf;
using namespace std;
Box::Box() {
	if (!tBox.loadFromFile("images/box.png"))
	{
		cout << "load player.png failed";
		EXIT_FAILURE;
	}
	sBox.setTexture(tBox);
}
void Box::setter(float x,float y) {
	this->x = x;
	this->y = y;
	this->sBox.setPosition(this->x, this->y);

}
sf::Sprite Box::getSprite() {
	return this->sBox;
};
void Box::drawBox(RenderWindow &window) {
	//sBox.setTextureRect(sf::IntRect(0 * 32, 0 * 32, 32, 32));
	window.draw(sBox);
}


