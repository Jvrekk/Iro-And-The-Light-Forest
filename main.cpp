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

	if (bulletTexture.loadFromFile("images/bullet.png")) {
		cout << "bullet.png load failed";
	}

	MouseDirections md;
	Player player;
	Enemy enemy;


	Entrance entrance, entrance2;

	entrance.setPosition(0, 0);
	entrance2.setPosition(1056, 0);

	//Main Loop:
	while (window.isOpen()) {

		player.movePlayer(window);
		enemy.moveEnemy();
		
		if (Mouse::isButtonPressed(Mouse::Left)) {
			bulletArr[counter].setter(player.getSprite().getPosition().x, player.getSprite().getPosition().y, md.mouseDirections(window, player.getSprite()), &bulletTexture, md.getRotation(window, player.getSprite()));
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
				player.die();
			}

			if (PixelPerfectTest(player.getSprite(), entrance.getGroundSprite())) {
				player.collision();
			}
			if (PixelPerfectTest(player.getSprite(), entrance2.getGroundSprite())) {
				player.collision();
			}
			if (PixelPerfectTest(player.getSprite(), entrance.getUpperGroundSprite())) {
				player.collision();
			}
			if (PixelPerfectTest(player.getSprite(), entrance2.getUpperGroundSprite())) {
				player.collision();
			}

			if (PixelPerfectTest(enemy.getSprite(), entrance.getGroundSprite())) {
				enemy.collision();
			}	
			if (PixelPerfectTest(enemy.getSprite(), entrance2.getGroundSprite())) {
				enemy.collision();
			}
			if (PixelPerfectTest(enemy.getSprite(), entrance.getGroundSprite())) {
				enemy.collision();
			}
			if (PixelPerfectTest(enemy.getSprite(), entrance2.getGroundSprite())) {
				enemy.collision();
			}



			player.drawPlayer(window);
			enemy.drawEnemy(window);

			for (int i = 0; i < magazin; i++) {
				bulletArr[i].drawBullet(window);
			}
			
		
			window.display();
			window.clear();
		}
	}
