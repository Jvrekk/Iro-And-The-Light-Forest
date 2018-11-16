#pragma once

#ifndef IRO_IN_THE_DARK_CHAMBER_BULLET_H
#define IRO_IN_THE_DARK_CHAMBER_BULLET_H
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "MouseDirections.h"
#include "Player.h"

using namespace sf;
using namespace std;

class Bullet : public Player, MouseDirections {
public:

	Bullet(float x,float y, Vector2f target, Texture *tex);
	void drawBullet(RenderWindow& window);
	void moveBullet(RenderWindow& window);

	bool outOfBounds();


private:
	Vector2f maxSpeed;
	Vector2f currentVelocity;
	Vector2f bTarget;
	sf::Sprite sBullet;
	sf::Texture tBullet;
};




#endif // !IRO_IN_THE_DARK_CHAMBER_BULLET_H