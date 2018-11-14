#pragma once
#include <cstdlib>
#include <iostream>
#include <sfml\graphics.hpp>
#include "bullet.h"
#include "MouseDirections.h"
#include "Player.h"



using namespace sf;
using namespace std;

Bullet::Bullet() {
	if (!tBullet.loadFromFile("images/bullet.png"))
	{
		cout << "load bullet.png failed";
		EXIT_FAILURE;
	}

	float x = Player::getSprite().getPosition().x;
	float y = Player::getSprite().getPosition().y;

	sBullet.setPosition(x,y	);

	sBullet.setTexture(tBullet);
}

void Bullet::drawBullet(RenderWindow& window) {

	window.draw(sBullet);
}

void Bullet::moveBullet(RenderWindow & win) {

	if (Mouse::isButtonPressed(Mouse::Left)) {
		sBullet.move(MouseDirections::mouseDirections(win, getSprite()));
	}
}

//TODO
bool Bullet::outOfBounds() {
	if(sBullet.getPosition().x > 600)
	return true;
}