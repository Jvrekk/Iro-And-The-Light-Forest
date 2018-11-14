#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "entrance.h"


using namespace sf;
using namespace std;
Entrance::Entrance() {
	if (!tGround.loadFromFile("images/mapa/entrance/ground.png")||!tUpperGround.loadFromFile("images/mapa/entrance/upperGround.png")||!tBackground.loadFromFile("images/mapa/entrance/background.png")){
		cout << "load entrance assets failed";
		EXIT_FAILURE;
	}
	sGround.setTexture(tGround);
	sUpperGround.setTexture(tUpperGround);
	sBackground.setTexture(tBackground);
}
void Entrance::setPosition(float x, float y) {
	this->x = x;
	this->y = y;
	this->sBackground.setPosition(this->x, this->y);
	this->sGround.setPosition(this->x, this->y);
	this->sUpperGround.setPosition(this->x, this->y);

}
sf::Sprite Entrance::getGroundSprite(){
	return this->sGround;
};
sf::Sprite Entrance::getUpperGroundSprite() {
	return this->sUpperGround;
};
void Entrance::draw(RenderWindow &window) {
	//sBox.setTextureRect(sf::IntRect(0 * 32, 0 * 32, 32, 32));
	window.draw(sBackground);
	window.draw(sGround);
	window.draw(sUpperGround);
}
