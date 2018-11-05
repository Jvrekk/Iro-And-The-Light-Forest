#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Gravity.h"
#include "Box.h"

#include "Collision.h"



using namespace sf;
using namespace std;

// zmienne globalne do kierunkow // Vector nie moze zostaw utworzony w non-static polu 
enum Directions {RIGHT, LEFT};
sf::Vector2i dir(0, RIGHT);


int main() {
	
	//WINDOW SETTINGS
	RenderWindow window;
	Vector2i centerWindow((VideoMode::getDesktopMode().width / 2) - 755, (VideoMode::getDesktopMode().height / 2) - 390);

	window.create(VideoMode(1500, 700), "Iro And The Light Forest", Style::Titlebar | Style::Close);
	window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);


	Player player;
	Box Box1;
	Box Box2;
	Box Box3;
	Box1.setter(128, 300);
	Box2.setter(256, 300);
	Box3.setter(512, 300);
	

	//Main Loop:
	while (window.isOpen()) {

		player.movePlayer();
		player.considerGravity();

		//Event Loop:
		Event Event;
		while (window.pollEvent(Event)) {
			switch (Event.type) {

			case Event::Closed:
				window.close();
				break;
			}
		}
	
		//loop textur			 TODO 
		//	dir.x++;
		//	if (dir.x * 32 >= texture.getSize().x)
		//	dir.x = 0;

		Box1.drawBox(window);
		Box2.drawBox(window);
		Box3.drawBox(window);
		player.drawPlayer(window);
		if (Collision::PixelPerfectTest(player.getSprite(), Box1.getSprite())) {
			cout << "COLLISION BOX1 DETECTED" << endl;
			player.collision();
		}
		if (Collision::PixelPerfectTest(player.getSprite(), Box2.getSprite())) {
			cout << "COLLISION BOX2 DETECTED" << endl;
			player.collision();
		}		
		if (Collision::PixelPerfectTest(player.getSprite(), Box3.getSprite())) {
			cout << "COLLISION BOX3 DETECTED" << endl;
			player.collision();
		}
		
		window.display();
		window.clear();
	}
}