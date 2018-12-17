#pragma once

#ifndef IRO_IN_THE_DARK_CHAMBER_ENEMY_H
#define IRO_IN_THE_DARK_CHAMBER_ENEMY_H
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Gravity.h"
#include "JetPack.h"
using namespace sf;
using namespace std;

class Enemy : public Gravity {
public:


	Enemy();

	void drawEnemy(RenderWindow &window);
	void moveEnemy();
	void considerGravity();
	void collision();
	void die();
	Sprite getSprite();


	int hp = 20;

private:
	float moveSpeed = 4;
	sf::Sprite sEnemy;
	sf::Texture tEnemy;

};
#endif // !IRO_IN_THE_DARK_CHAMBER_ENEMY_H
