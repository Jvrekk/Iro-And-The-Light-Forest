#pragma once
#include <cstdlib>
#include <iostream>
#include <sfml\graphics.hpp>
#include "bullet.h"
#include "MouseDirections.h"
#include "Player.h"



using namespace sf;
using namespace std;

Bullet::Bullet(float x,float y, Vector2f target, Texture *tex) {

	bTarget = target;

	sBullet.setPosition(x,y);
	
	sBullet.setTexture(*tex);
}

void Bullet::drawBullet(RenderWindow& window) {
	window.draw(sBullet);
}

void Bullet::moveBullet(RenderWindow & win) {
		sBullet.move(bTarget);
}

//TODO
bool Bullet::outOfBounds() {
	if(sBullet.getPosition().x >= 1920 || sBullet.getPosition().x <= 0 || sBullet.getPosition().y >= 1080 || sBullet.getPosition().y <= 0)
	return true;
}