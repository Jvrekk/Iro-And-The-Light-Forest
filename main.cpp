#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include <list>
#include "Gravity.h"
#include "Box.h"
#include "Bullet.h"
#include "Collision.h"
#include "MouseDirections.h"
#include "entrance.h"
#include "Settings.h"
#include "Animations.h"
#include "Menu.h"
#include <vector>

using namespace sf;
using namespace std;
using namespace Collision;
float czas = 0;
float switchT = 0.1f;
float totalT = 0.2f;
sf::Clock clock2;
int enemyAmount = 1;
int enemyCount = 1;
int enemyKill = 0;
int main() {

	srand(time(NULL));
	//WINDOW SETTINGS
	RenderWindow window;
	Vector2i centerWindow((VideoMode::getDesktopMode().width / 2) - 755, (VideoMode::getDesktopMode().height / 2) - 390);

	window.create(VideoMode(Settings::windowWidth, Settings::windowHeight), "Iro And The Light Forest", Style::Titlebar | Style::Close);
	window.setPosition(centerWindow);
	window.setFramerateLimit(Settings::FPS);
	
	window.setKeyRepeatEnabled(true);

	//Array of bullets
	int counter = 0;
	const int magazin = 100;
	Bullet bulletArr[magazin];

    Texture bulletTexture;

	if (!bulletTexture.loadFromFile("images/bullet.png")) {
		cout << "bullet.png load failed";
	}
	Menu menu;
	MouseDirections md;
	Texture tPlayer;

	Settings settings;

	if (!tPlayer.loadFromFile("images/player.png"))
	{
		cout << "load player.png failed";
		EXIT_FAILURE;
	}
	//sf::Texture* texture,sf::Vector2u imageCount, float switchTime) : animation(texture, imageCount, switchTime){
	Player player(&tPlayer,sf::Vector2u(4,3), 0.3f);
	
	Texture tEnemy;
	if (!tEnemy.loadFromFile("images/enemy.png"))
	{
		cout << "load enemy.png failed";
		EXIT_FAILURE;
	}
	Box box1,box2;
	box1.setter(0, 500);
	box2.setter(2112,500);
	Enemy enemyArr[100];
	for (int i = 0; i < enemyAmount; i++) {
		enemyArr[i] = { &tEnemy, sf::Vector2u(4, 2), 0.3f, 100+i*80, -300 };
		enemyArr[i].hp = 100;
	}

	float deltaTime = 0.0;
	sf::Clock clock;

	Entrance entrance, entrance2;

	entrance.setPosition(0, 0);
	entrance2.setPosition(1056, 0);

	
	//Main Loop:
	while (window.isOpen() && menu.isRuning) {

		if (menu.startingPage) {
			menu.drawStartingPage(window);
		}
		if (menu.menu) {
			menu.drawMenu(window);
		}
		if (menu.play) {
			//
			deltaTime = clock.restart().asSeconds();
			czas = clock2.getElapsedTime().asSeconds();
			//
			//	player.movePlayer(window);
			totalT += deltaTime;
			if (totalT >= switchT) {
				totalT -= switchT;
				if (Mouse::isButtonPressed(Mouse::Left)) {

					bulletArr[counter].setter(player.getSprite().getPosition().x, player.getSprite().getPosition().y, md.mouseDirections(window, player.getSprite(), player.xmov), &bulletTexture, md.getRotation(window, player.getSprite(), player.xmov));
					counter++;


					if (counter >= 100)
						counter = 0;
				}
			}
				
	
			//Event Loop:
			Event Event;
			while (window.pollEvent(Event)) {

				switch (Event.type) {

				case Event::Closed:
					window.close();
					break;
				}
			}

			player.considerGravity();
		

			entrance.draw(window);
			entrance2.draw(window);
			box1.drawBox(window);
			box2.drawBox(window);

			//KOLIZJE
			for (int i = 0; i < magazin; i++) {
				if (PixelPerfectTest(bulletArr[i].getSprite(), entrance.getGroundSprite())) {
					bulletArr[i].collision();
				}
				if (PixelPerfectTest(bulletArr[i].getSprite(), entrance2.getGroundSprite())) {
					bulletArr[i].collision();
				}
				if (PixelPerfectTest(bulletArr[i].getSprite(), entrance.getUpperGroundSprite())) {
					bulletArr[i].collision();
				}
				if (PixelPerfectTest(bulletArr[i].getSprite(), entrance2.getUpperGroundSprite())) {
					bulletArr[i].collision();
				}

			}

	

	
			player.Update(deltaTime, window);


			player.considerCollisions(player, entrance, entrance2);

			player.drawPlayer(window);
			for (int i = 0; i < enemyAmount; i++) {
				if (PixelPerfectTest(box1.getSprite(), enemyArr[i].getSprite())) {
					enemyArr[i].collisionBox();
				}
				if (PixelPerfectTest(box2.getSprite(), enemyArr[i].getSprite())) {
					enemyArr[i].collisionBox();
				}
				if (PixelPerfectTest(player.getSprite(), enemyArr[i].getSprite())) {
					int i = player.getHp();
					i -= 2;
					player.setHp(i);
					if (player.getHp() < 0) {
						player.die(window);
					}
				}

				enemyArr[i].drawEnemy(window);
				enemyArr[i].considerGravity();
				enemyArr[i].considerCollisions(enemyArr[i], entrance, entrance2);
				enemyArr[i].moveEnemy(deltaTime, player.getSprite());
				for (int j = 0; j < magazin; j++) {
					if (PixelPerfectTest(bulletArr[j].getSprite(), enemyArr[i].getSprite())) {
						bulletArr[j].collision();
						enemyArr[i].hp -= 15;
						if (enemyArr[i].hp <= 0) {
							enemyArr[i].die();
							enemyKill++;
						}
					}
				}

			}

			for (int i = 0; i < magazin; i++) {
				bulletArr[i].drawBullet(window);
			}
			if (enemyKill == enemyAmount) {
				enemyAmount++;
				enemyKill = 0;
				for (int i = 0; i < enemyAmount; i++) {
					enemyArr[i] = { &tEnemy, sf::Vector2u(4, 2), 0.3f, (rand()%2000+0), -300 };
					enemyArr[i].hp = 100;
				}
			}
			//cout << "size "<<window.getSize().x << "     " << window.getSize().y << endl;
			cout << "position " << window.getPosition().x << "     " << window.getPosition().y << endl;
			window.display();
			window.clear();

			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				menu.play = false;
				menu.menu = true;
			}
		}
		}
	}
