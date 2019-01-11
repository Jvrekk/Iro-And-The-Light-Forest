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

Enemy::Enemy(sf::Texture * texture, sf::Vector2u imageCount, float switchTime) : animation(texture, imageCount, switchTime) {

	row = 0;
	faceRight = false;
	sEnemy.setPosition(sf::Vector2f(Settings::windowWidth + 600, -300));
	sEnemy.setTexture(*texture);
}

void Enemy::drawEnemy(RenderWindow &window) {
	window.draw(sEnemy);
}

void Enemy::moveEnemy(float deltaTime) {

	sf::Vector2f movement(0.0f, 0.0f);

		movement.x -= moveSpeed * deltaTime * 100;
		row = 0;

	animation.Update(row, deltaTime, faceRight);
	sEnemy.setTextureRect(animation.uvRect);
	movement.x /= 3;
	sEnemy.move(movement);
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




