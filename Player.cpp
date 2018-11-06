#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Gravity.h"
#include "Gravity.cpp"
#include "Player.h"

using namespace sf;
using namespace std;

	
	Player::Player() {
		if (!tPlayer.loadFromFile("images/player.png"))
		{
			cout << "load player.png failed";
			EXIT_FAILURE;
		}
		sPlayer.setTexture(tPlayer);
	}

	void Player::drawPlayer(RenderWindow &window) {
		sPlayer.setTextureRect(sf::IntRect(0 * sPlayer.getGlobalBounds().width, 0 * sPlayer.getGlobalBounds().height, 32, 32));
		window.draw(sPlayer);
	}

	void Player::movePlayer() {

		jetpack();

		if (Keyboard::isKeyPressed(Keyboard::A)) {
			sPlayer.move(-moveSpeed, 0);
	
		}
		 if (Keyboard::isKeyPressed(Keyboard::D)) {
			sPlayer.move(moveSpeed, 0);
		}
	}


	void Player::jetpack() {

		fuel += fuelLoss;

		if (fuel > fuelMax) fuel = fuelMax;
		if (fuel < 0) fuel = 0;

		if (Keyboard::isKeyPressed(Keyboard::W)) {

			if (jumpAble) {
				fuelLoss = -fuelUsage * 3;
				sPlayer.move(0, -moveSpeed * 2);
				if (fuel <= 1)
					jumpAble = false;
			}
			else {
				fuel += fuelUsage;
				if (fuel >= fuelMax / 2)
					jumpAble = true;
			}
		}
		else {
			fuelLoss = fuelUsage;
		}

	}

	void Player::considerGravity() {
		Gravity::considerGravity(sPlayer);
	}
	void Player::collision() {
		sPlayer.move(0, -moveSpeed);
	}
	sf::Sprite Player::getSprite() {
		return this->sPlayer;
	};




