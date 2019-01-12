#pragma once

#ifndef IRO_IN_THE_DARK_CHAMBER_ENEMY_H
#define IRO_IN_THE_DARK_CHAMBER_ENEMY_H
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Gravity.h"
#include "JetPack.h"
#include "Entrance.h"
#include "Animations.h"

using namespace sf;
using namespace std;

class Enemy : public Gravity {
public:

	Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,int x,int y);
	Enemy() {};

	void drawEnemy(RenderWindow &window);
	void moveEnemy(float deltaTime, sf::Sprite player);
	
	void considerGravity();
	void collision();
	void die();
	Sprite getSprite();
	void considerCollisions(Enemy& e, Entrance& env, Entrance& env2);

	int hp = 100;
	int hpMax = 100;
	float randomMove = 0;

private:
	float moveSpeed = 7;
	Animations animation;
	sf::RectangleShape body;
	bool faceRight;
	unsigned int row;


	sf::Sprite sEnemy;
	sf::Texture tEnemy;

	sf::RectangleShape hpMaxBar;
	sf::RectangleShape hpActBar;

};
#endif // !IRO_IN_THE_DARK_CHAMBER_ENEMY_H
