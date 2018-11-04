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
		sPlayer.setTextureRect(sf::IntRect(0 * 32, 0 * 32, 32, 32));
	}

	void Player::movePlayer() {

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			sPlayer.move(0, -moveSpeed * 3);
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			sPlayer.move(-moveSpeed, 0);
	
		}
		else if (Keyboard::isKeyPressed(Keyboard::D)) {
			sPlayer.move(moveSpeed, 0);
		}
	}

	void Player::considerGravity() {
		Gravity::considerGravity(sPlayer);
	}



