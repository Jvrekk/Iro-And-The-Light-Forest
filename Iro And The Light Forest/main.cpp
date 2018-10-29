#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;
using namespace std;





int main() {
	//BASE SETTINGS
	Player Player(50);
	
	//WINDOW SETTINGS
	RenderWindow window;
	Vector2i centerWindow((VideoMode::getDesktopMode().width / 2) - 755, (VideoMode::getDesktopMode().height / 2) - 390);

	window.create(VideoMode(1500, 700), "Iro And The Light Forest", Style::Titlebar | Style::Close);
	window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);

	

	//Main Loop:
	while (window.isOpen()) {

		Event Event;
		Player.movePlayer();
		
		//Event Loop:
		while (window.pollEvent(Event)) {
			switch (Event.type) {

			case Event::Closed:
				window.close();
			

			case sf::Event::KeyReleased:
				Player.isJumping = false;
		}

		
			
			
		}
		window.clear();
		Player.drawPlayer(window);
		window.display();
	}
}