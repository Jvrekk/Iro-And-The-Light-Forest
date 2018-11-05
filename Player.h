#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Gravity.h"
#ifndef IRO_IN_THE_DARK_CHAMBER_PLAYER_H
#define IRO_IN_THE_DARK_CHAMBER_PLAYER_H

using namespace sf;
using namespace std;

class Player : public Gravity {
public:
	

	Player();
	void drawPlayer(RenderWindow &window);
	void movePlayer();
	void considerGravity();
	void collision();
	sf::Sprite getSprite();
	
private:

	float moveSpeed = 0.2;
	sf::Sprite sPlayer;
	sf::Texture tPlayer;
};
#endif // !IRO_IN_THE_DARK_CHAMBER_PLAYER_H
