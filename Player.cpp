#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Gravity.h"
#include "JetPack.h"
#include "Player.h"
#include "MouseDirections.h"
#include "Settings.h"

using namespace sf;
using namespace std;


Player::Player() {
	if (!tPlayer.loadFromFile("images/playerScale.png"))
	{
		cout << "load player.png failed";
		EXIT_FAILURE;
	}
	sPlayer.setPosition(sf::Vector2f(Settings::windowWidth / 2, Settings::windowHeight / 2));
	sPlayer.setTexture(tPlayer);
	followPlayer.setCenter(Settings::windowWidth / 2, Settings::windowHeight / 2);
	followPlayer.setSize(Settings::windowWidth, Settings::windowHeight);
}

void Player::drawPlayer(RenderWindow &window) {

	enum Directions { RIGHT, LEFT };
	sf::Vector2i dir(0, RIGHT);
	if (MouseDirections::getRotation(window, sPlayer)> 180){
		
		sPlayer.setTextureRect(sf::IntRect(dir.x * sPlayer.getGlobalBounds().width, LEFT * sPlayer.getGlobalBounds().height, 128, 128));
	}
	else if(MouseDirections::getRotation(window, sPlayer) < 180){
		sPlayer.setTextureRect(sf::IntRect(dir.x * sPlayer.getGlobalBounds().width, RIGHT * sPlayer.getGlobalBounds().height, 128, 128));
	}
		JetPack::draw(window);
		window.draw(sPlayer);
		window.setView(followPlayer);
	}

	void Player::movePlayer() {

		jetpack();
		//followPlayer.move(sPlayer.getPosition().x, sPlayer.getPosition().y);
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			sPlayer.move(-moveSpeed, 0);
			followPlayer.move(-moveSpeed,0);
	
		}
		 if (Keyboard::isKeyPressed(Keyboard::D)) {
			sPlayer.move(moveSpeed, 0);
			followPlayer.move(moveSpeed, 0);
		}
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

