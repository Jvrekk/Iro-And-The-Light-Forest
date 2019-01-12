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

Enemy::Enemy(sf::Texture * texture, sf::Vector2u imageCount, float switchTime,int x,int y) : animation(texture, imageCount, switchTime) {
	srand(time(NULL));
	row = 0;
	faceRight = false;
	//sEnemy.setPosition(sf::Vector2f(Settings::windowWidth + (rand() % 600) + 0, -300));
	sEnemy.setPosition(sf::Vector2f(x,y));
	sEnemy.setTexture(*texture);
}

void Enemy::drawEnemy(RenderWindow &window) {
	window.draw(sEnemy);
	hpMaxBar.setSize(Vector2f(hpMax/2, 8));
	hpMaxBar.setPosition(Vector2f(this->sEnemy.getPosition()));
	hpMaxBar.setFillColor(sf::Color(135, 135, 135));
	hpActBar.setSize(Vector2f(hp/2, 8));
	hpActBar.setPosition(Vector2f(this->sEnemy.getPosition()));
	hpActBar.setFillColor(sf::Color(0, 150, 0));
	window.draw(hpMaxBar);
	window.draw(hpActBar);
}

void Enemy::moveEnemy(float deltaTime, sf::Sprite player) {

	sf::Vector2f movement(0.0f, 0.0f);


	if (player.getPosition().y - this->sEnemy.getPosition().y >=20 ) {
		if (player.getPosition().x > this->sEnemy.getPosition().x) {
			movement.x += moveSpeed * deltaTime * 100;
			this->randomMove = moveSpeed * deltaTime * 100;
			row = 0;
		}
			
		
		if (player.getPosition().x < this->sEnemy.getPosition().x) {
			movement.x -= moveSpeed * deltaTime * 100;
			this->randomMove = moveSpeed * deltaTime * -100;
			row = 1;
		}
		
		
	}	
	else {
		movement.x += randomMove;
	}


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




