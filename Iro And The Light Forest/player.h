#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;

class Player {
public:
	Player() {
		//Default
	}

	Player(int size) {
		shape.setRadius(size);		
	}

	void drawPlayer(RenderWindow &window) {
		window.draw(shape);
	}

	void movePlayer() {
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			shape.move(0.f, -moveSpeed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			shape.move(0, moveSpeed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::A)) {
			shape.move(-moveSpeed, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::D)) {
			shape.move(moveSpeed, 0);
		}

	}
private:
	CircleShape shape;
	float moveSpeed = 6;
};