#pragma once


#ifndef IRO_IN_THE_DARK_CHAMBER_PLAYER_H
#define IRO_IN_THE_DARK_CHAMBER_PLAYER_H
#include "MouseDirections.h"
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Gravity.h"
#include "JetPack.h"
#include "Entrance.h"
#include "Animations.h"
using namespace sf;
using namespace std;

class Player : public JetPack, Gravity, MouseDirections {
public:

	Player();
	Player(sf::Texture* texture,sf::Vector2u imageCount, float switchTime);


	void drawPlayer(RenderWindow &window);
	void movePlayer(RenderWindow &window);
	void considerGravity();
	void collision();
	void die(RenderWindow & window);
	void jetpack();
	Sprite getSprite();
	void die();
	void considerCollisions(Player& pla, Entrance& env, Entrance& env2);
	void drawPlayerHp(RenderWindow & window);
	void Update(float deltaTime, RenderWindow &window);
	void setHp(int hp);
	int getHp();
	

private:
	float moveSpeed = 7;
	Animations animation;
	sf::RectangleShape body;
	bool faceRight;
	unsigned int row; 

	int hp = 150;
	int hpMax = 150;

	sf::Sprite sPlayer;
	sf::Texture tPlayer;
	sf::View followPlayer;

	sf::RectangleShape hpMaxBar ;
	sf::RectangleShape hpActBar;
};
#endif // !IRO_IN_THE_DARK_CHAMBER_PLAYER_H