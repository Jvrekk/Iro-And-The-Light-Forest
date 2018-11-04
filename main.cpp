#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Gravity.h"

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


	Player Player;
	

	//Main Loop:
	while (window.isOpen()) {

		Player.movePlayer();
		Player.considerGravity();


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

		
		Player.drawPlayer(window);
		window.display();
		window.clear();
	}
}