#pragma once

#ifndef IRO_IN_THE_DARK_CHAMBER_ENTRANCE_H
#define IRO_IN_THE_DARK_CHAMBER_ENTRANCE_H
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;

class Entrance {
public:
	Entrance();
	void setPosition(float x, float y);
	void draw(RenderWindow &window);
	sf::Sprite getGroundSprite();
	sf::Sprite getUpperGroundSprite();
private:
	float x, y;
	sf::Sprite sGround,sUpperGround, sBackground;
	sf::Texture tGround, tUpperGround, tBackground;
};

#endif // !IRO_IN_THE_DARK_CHAMBER_BOX_H

