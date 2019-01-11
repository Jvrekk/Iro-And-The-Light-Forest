#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Gravity.h"
#include "Enemy.h"
#include "Settings.h"
#include "entrance.h"
#include "Collision.h"


using namespace sf;
using namespace std;
using namespace Collision;

Enemy::Enemy() {
	if (!tEnemy.loadFromFile("images/enemy.png"))
	{
		cout << "load enemy.png failed";
		EXIT_FAILURE;
	}

	sEnemy.setPosition(sf::Vector2f(Settings::windowWidth + 600 , -1000));
	sEnemy.setTexture(tEnemy);
}

void Enemy::drawEnemy(RenderWindow &window) {
	window.draw(sEnemy);
}

void Enemy::moveEnemy() {
	sEnemy.move(-moveSpeed/2, 0);
}


void Enemy::considerGravity() {
	Gravity::considerGravity(sEnemy);
}

void Enemy::collision() {
	sEnemy.move(0, -moveSpeed);
}

void Enemy::die() {
	sEnemy.setPosition(-19999, -19999);
}

sf::Sprite Enemy::getSprite() {
	
	return this->sEnemy;
}

void Enemy::considerCollisions(Enemy& ene, Entrance& env, Entrance& env2)
{
	if (PixelPerfectTest(ene.getSprite(), env.getGroundSprite())) {
		ene.collision();
	}
	if (PixelPerfectTest(ene.getSprite(), env2.getGroundSprite())) {
		ene.collision();
	}
	if (PixelPerfectTest(ene.getSprite(), env.getUpperGroundSprite())) {
		ene.collision();
	}
	if (PixelPerfectTest(ene.getSprite(), env2.getUpperGroundSprite())) {
		ene.collision();
	}
}




