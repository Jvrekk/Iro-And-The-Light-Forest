#pragma once
#include <cstdlib>
#include <iostream>
#include <sfml\graphics.hpp>
#include "bullet.h"
#include "MouseDirections.h"
#include "Player.h"



using namespace sf;
using namespace std;

Bullet::Bullet(float x,float y) {

	if (!tBullet.loadFromFile("images/bullet.png"))
	{
		cout << "load bullet.png failed";
		EXIT_FAILURE;
	}
	sBullet.setPosition(x,y);
	
	sBullet.setTexture(tBullet);
}

void Bullet::drawBullet(RenderWindow& window) {
	window.draw(sBullet);
}

void Bullet::moveBullet(RenderWindow & win) {
		sBullet.move(MouseDirections::mouseDirections(win, getSprite()));
}

//TODO
bool Bullet::outOfBounds() {
	if(sBullet.getPosition().x >= 1200 )
	return true;
}