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


	drawPlayerHp(window);
	JetPack::draw(window,this->xmov);
	window.draw(sPlayer);
	window.setView(followPlayer);
}


void Player::drawPlayerHp(RenderWindow &window) {

	hpMaxBar.setSize(Vector2f(hpMax * 2, 40));
	hpMaxBar.setPosition(Vector2f(360+this->xmov, 620));
	hpMaxBar.setFillColor(sf::Color(135, 135, 135));
	hpActBar.setSize(Vector2f(hp * 2, 40));
	hpActBar.setPosition(Vector2f(360 + this->xmov, 620));
	hpActBar.setFillColor(sf::Color(0, 150, 0));
	


	hpActBar.setSize(Vector2f(hp * 2, 40));
	window.draw(hpMaxBar);
	window.draw(hpActBar);
}

void Player::Update(float deltaTime, RenderWindow &window) {
	


	sf::Vector2f movement(0.0f, 0.0f);

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		movement.x -= moveSpeed * deltaTime * 100;
		this->xmov -= moveSpeed * deltaTime * 100;
	}
		

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		movement.x += moveSpeed * deltaTime * 100;
		this->xmov += moveSpeed * deltaTime * 100;
	}
		

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

void Player::setHp(int hp)
{
	this->hp = hp;
}

int Player::getHp()
{
	return this->hp;
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

void Player::die(RenderWindow & window) {
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

