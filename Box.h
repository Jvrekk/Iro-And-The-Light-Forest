#pragma once

#ifndef IRO_IN_THE_DARK_CHAMBER_BOX_H
#define IRO_IN_THE_DARK_CHAMBER_BOX_H
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;

class Box {
public:
	Box();
	void setter(float x,float y);
	void drawBox(RenderWindow &window);
	sf::Sprite getSprite();
private:
	float x,y;
	sf::Sprite sBox;
	sf::Texture tBox;
};

#endif // !IRO_IN_THE_DARK_CHAMBER_BOX_H

