#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Gravity.h"
#include "Box.h"
#include "Collision.h"
#include "MouseDirections.h"
#include "entrance.h"



using namespace sf;
using namespace std;
using namespace Collision;




int main() {
	
	//WINDOW SETTINGS
	RenderWindow window;
	Vector2i centerWindow((VideoMode::getDesktopMode().width / 2) - 755, (VideoMode::getDesktopMode().height / 2) - 390);

	window.create(VideoMode(1500, 672), "Iro And The Light Forest", Style::Titlebar | Style::Close);
	window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);

	MouseDirections md;
	Player player;

	Entrance entrance,entrance2;

	entrance.setPosition(0, 0);
	entrance2.setPosition(1056, 0);



	//Main Loop:
	while (window.isOpen()) {

		player.movePlayer();
		

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
		if (PixelPerfectTest( player.getSprite(), entrance.getGroundSprite() )){
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
		player.drawPlayer(window);

		
		window.display();
		window.clear();
	}
}