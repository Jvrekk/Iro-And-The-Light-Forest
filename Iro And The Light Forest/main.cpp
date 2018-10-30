#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "box.h"
using namespace sf;
using namespace std;




int main() {
	//BASE SETTINGS
	Player Player(50);
	Box boxArr[10],boxArr2[10];
	for (int i = 0; i < 10; i++) {
		boxArr[i].setter(50, i * 50, 200);
		boxArr2[i].setter(50, 500 + i * 50, 400);
	}
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
		}

		
			
			
		}
		window.clear();
		Player.drawPlayer(window);
		for (int i = 0; i < 10; i++) {
			boxArr[i].drawBox(window);
			boxArr2[i].drawBox(window);
		}		
		window.display();
	}
}