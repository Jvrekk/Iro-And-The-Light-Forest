//#pragma once
//#include <cstdlib>
//#include <iostream>
//#include <SFML\Graphics.hpp>
//#include "Bullet.h"
//#include "MouseDirections.h"
//#include "Player.h"
//
//
//using namespace sf;
//using namespace std;
//
//
//Bullet::Bullet() {
//	if (!tBullet.loadFromFile("images/bullet.png"))
//	{
//		cout << "load bullet.png failed";
//		EXIT_FAILURE;
//	}
//	sBullet.setTexture(tBullet);
//}
//void Bullet::drawBullet(RenderWindow &win) {
//
//	enum Directions { RIGHT, LEFT };
//	sf::Vector2i dir(0, RIGHT);
//
//	win.draw(sBullet);
//}
//
//void Bullet::moveBullet(RenderWindow &win) {
//	if (Mouse::isButtonPressed(Mouse::Left)) {
//		Vector2f shotDir = mouseDirections(win, getSprite());
//		sBullet.move(shotDir);
//	}
//}
