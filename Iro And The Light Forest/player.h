#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;

class Player {
public:
	bool isJumping;
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
			player.move(0.f, -moveSpeed);
			isJumping = true;
		}
		else if (Keyboard::isKeyPressed(Keyboard::A)) {
			player.move(-moveSpeed, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::D)) {
			player.move(moveSpeed, 0);
		}

	}

	int getX() {
		player.getPosition().x;
	}

	int getY() {
		player.getPosition().y;
	}


private:
	CircleShape player;
	float moveSpeed = 2.1;
	
	
};