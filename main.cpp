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

int main() {


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
	
	Enemy enemy(&tEnemy, sf::Vector2u(4, 2), 0.3f);

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
			//
			//	player.movePlayer(window);

			if (Mouse::isButtonPressed(Mouse::Left)) {
				bulletArr[counter].setter(player.getSprite().getPosition().x, player.getSprite().getPosition().y, md.mouseDirections(window, player.getSprite(),player.xmov), &bulletTexture, md.getRotation(window, player.getSprite(),player.xmov));
				counter++;
				if (counter >= 100)
					counter = 0;
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
			enemy.considerGravity();
		

			entrance.draw(window);
			entrance2.draw(window);

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
				if (PixelPerfectTest(bulletArr[i].getSprite(), enemy.getSprite())) {
					bulletArr[i].collision();
					enemy.hp -= 1;
					if (enemy.hp == 0) {
						enemy.die();
					}
				}
			}
			if (PixelPerfectTest(player.getSprite(), enemy.getSprite())) {
				int i = player.getHp();
				i-=2;
				player.setHp(i);
				if (player.getHp() < 0) {
					player.die(window);
				}
			}
	

			enemy.considerCollisions(enemy, entrance, entrance2);
	
			player.Update(deltaTime, window);
			enemy.moveEnemy(deltaTime,player.getSprite());


			player.considerCollisions(player, entrance, entrance2);

			player.drawPlayer(window);
			enemy.drawEnemy(window);

			for (int i = 0; i < magazin; i++) {
				bulletArr[i].drawBullet(window);
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
