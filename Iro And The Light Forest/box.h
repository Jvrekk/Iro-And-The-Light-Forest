#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;

class Box {
public:
	Box() {
		this->box.setFillColor(Color::Blue);
	}
	Box(int size,float x,float y) {
		this->box.setSize(Vector2f(size,size));
		this->box.setPosition(x, y);
		
	}
	void setter(int size, float x, float y) {
		this->box.setSize(Vector2f(size, size));
		this->box.setPosition(x, y);
	}
	void drawBox(RenderWindow &window) {
		window.draw(box);
	}

	int getX() {
		return this->box.getPosition().x;
	}

	int getY() {
		return this->box.getPosition().y;
	}


private:
	RectangleShape box;
};