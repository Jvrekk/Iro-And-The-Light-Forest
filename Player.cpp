#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Gravity.h"
#include "JetPack.h"
#include "Player.h"
#include "MouseDirections.h"
#include "Settings.h"
#include "entrance.h"
#include "Collision.h"

using namespace sf;
using namespace std;
using namespace Collision;

enum Directions { RIGHT, LEFT };
sf::Vector2i dir(0, RIGHT);
bool pos;


Player::Player()
{
}

Player::Player(sf::Texture* texture,sf::Vector2u imageCount, float switchTime) : animation(texture, imageCount, switchTime){
	
	faceRight = true;

	row = 0;
	faceRight = true;
	// sPlayer.setOrigin(sf::Vector2f(256.0f, 256.0f));
	sPlayer.setPosition(sf::Vector2f(Settings::windowWidth / 2, Settings::windowHeight / 2));
	sPlayer.setTexture(*texture);
	followPlayer.setCenter(Settings::windowWidth / 2, Settings::windowHeight / 2);
	followPlayer.setSize(Settings::windowWidth, Settings::windowHeight);
}



void Player::drawPlayer(RenderWindow &window) {

	/*
	if (MouseDirections::getRotation(window, sPlayer)> 180) {
		sPlayer.setTextureRect(sf::IntRect(dir.x * sPlayer.getGlobalBounds().width, LEFT * sPlayer.getGlobalBounds().height, 128, 128));
		pos = false;
	}
	else if (MouseDirections::getRotation(window, sPlayer) < 180) {
		sPlayer.setTextureRect(sf::IntRect(dir.x * sPlayer.getGlobalBounds().width, RIGHT * sPlayer.getGlobalBounds().height, 128, 128));
		pos = true;
	}
	*/
	JetPack::draw(window);
	window.draw(sPlayer);
	window.setView(followPlayer);
}



void Player::Update(float deltaTime, RenderWindow &window) {
	


	sf::Vector2f movement(0.0f, 0.0f);

	if (Keyboard::isKeyPressed(Keyboard::A)) 
		movement.x -= moveSpeed * deltaTime *100;

	if (Keyboard::isKeyPressed(Keyboard::D)) 
		movement.x += moveSpeed * deltaTime * 100;

	if (movement.x == 0.0f){
		row = 0;
	}
	else {
	

		if (movement.x > 0.0f) {
			row = 1;
		}
		else{
			row = 2;
		}
	}
	jetpack();
	animation.Update(row, deltaTime, faceRight);
	sPlayer.setTextureRect(animation.uvRect);
	sPlayer.move(movement);
	followPlayer.move(movement);
	
}

void Player::movePlayer(RenderWindow &window) {

	jetpack();
	//followPlayer.move(sPlayer.getPosition().x, sPlayer.getPosition().y);
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		sPlayer.move(-moveSpeed, 0);
		followPlayer.move(-moveSpeed, 0);

	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		sPlayer.move(moveSpeed, 0);
		followPlayer.move(moveSpeed, 0);
	}

	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		if (MouseDirections::getRotation(window, sPlayer) < 180) {
			sPlayer.setPosition(sPlayer.getPosition().x + 60, sPlayer.getPosition().y);
			followPlayer.move(moveSpeed + 60, 0);
		}
		if ((MouseDirections::getRotation(window, sPlayer) > 180))
		{
			sPlayer.setPosition(sPlayer.getPosition().x - 60, sPlayer.getPosition().y);
			followPlayer.move(moveSpeed - 60, 0);
		}
	}

}

void Player::considerCollisions(Player& pla, Entrance& env, Entrance& env2)
{
	if (PixelPerfectTest(pla.getSprite(), env.getGroundSprite())) {
		pla.collision();
	}
	if (PixelPerfectTest(pla.getSprite(), env2.getGroundSprite())) {
		pla.collision();
	}
	if (PixelPerfectTest(pla.getSprite(), env.getUpperGroundSprite())) {
		pla.collision();
	}
	if (PixelPerfectTest(pla.getSprite(), env2.getUpperGroundSprite())) {
		pla.collision();
	}
}



void Player::die() {
	sPlayer.setPosition(-19999, -19999);
}

void Player::jetpack() {
	JetPack::Fly(sPlayer);
}

void Player::considerGravity() {
	Gravity::considerGravity(sPlayer);
}

void Player::collision() {
	sPlayer.move(0, -moveSpeed);
}
sf::Sprite Player::getSprite() {
	return this->sPlayer;
}
