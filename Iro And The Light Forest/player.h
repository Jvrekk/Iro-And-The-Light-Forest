#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "box.h"
#include "gravity.h"

using namespace sf;
using namespace std;
class Box;

class Player : public Gravity {
public:

	Player() {
		//Default
	}
	

	Player(int size) {
		player.setRadius(size);
	}

	void drawPlayer(RenderWindow &window) {
		window.draw(player);
	}

	void movePlayer() {

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			player.move(0, -moveSpeed*3);
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			player.move(-moveSpeed, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::D)) {
			player.move(moveSpeed, 0);
		}

	}

	void considerGravity() {
		Gravity::considerGravity(player);
	}


	int getX() {
	
		return player.getPosition().x;
	}

	int getY() {
		return player.getPosition().y;
	}

	void setX(float x) {
		player.setPosition(x, player.getPosition().y);
	}


	void setY(float y) {
		player.setPosition(player.getPosition().x, y);
	}



private:
	CircleShape player;
 
	float moveSpeed = 0.5;


};
