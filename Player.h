#pragma once


#ifndef IRO_IN_THE_DARK_CHAMBER_PLAYER_H
#define IRO_IN_THE_DARK_CHAMBER_PLAYER_H
#include "MouseDirections.h"
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Gravity.h"
#include "JetPack.h"
using namespace sf;
using namespace std;

class Player : public JetPack, Gravity, MouseDirections {
public:
	

	Player();
	
	void drawPlayer(RenderWindow &window);
	void movePlayer();
	void considerGravity();
	void collision();
	void jetpack();
	Sprite getSprite();

	



private:
	float moveSpeed = 7;
	sf::Sprite sPlayer;
	sf::Texture tPlayer;
	sf::View followPlayer;
};
#endif // !IRO_IN_THE_DARK_CHAMBER_PLAYER_H
