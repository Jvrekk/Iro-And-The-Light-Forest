#pragma once
#include <cstdlib>
#include <iostream>
#include <sfml\graphics.hpp>
#include "bullet.h"
#include "MouseDirections.h"
#include "Player.h"



using namespace sf;
using namespace std;
Bullet::Bullet() {};
Bullet::Bullet(float x,float y, Vector2f target, Texture *tex, float direction) {

	bTarget = target;

	sBullet.setPosition(x+20,y);
	sBullet.setTexture(*tex);
	sBullet.setRotation(direction);
}
void Bullet::setter(float x, float y, Vector2f target, Texture *tex, float direction) {

	bTarget = target;

	sBullet.setPosition(x, y);
	sBullet.setTexture(*tex);
	sBullet.setRotation(direction);
}

void Bullet::drawBullet(RenderWindow& window) {
	Bullet::moveBullet(window);
	window.draw(sBullet);
}

void Bullet::moveBullet(RenderWindow & win) {
		sBullet.move(bTarget);
}
sf::Sprite Bullet::getSprite() {
	return this->sBullet;
}
void Bullet::collision() {
	this->sBullet.setPosition(-200, -200);
	bTarget = Vector2f(0,0);
}

//TODO
bool Bullet::outOfBounds() {
	if(sBullet.getPosition().x >= 1920 || sBullet.getPosition().x <= 0 || sBullet.getPosition().y >= 1080 || sBullet.getPosition().y <= 0)
	return true;
}