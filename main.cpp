#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Gravity.h"
#include "Box.h"
#include "Collision.h"
#include "MouseDirections.h"



using namespace sf;
using namespace std;




int main() {
	
	//WINDOW SETTINGS
	RenderWindow window;
	Vector2i centerWindow((VideoMode::getDesktopMode().width / 2) - 755, (VideoMode::getDesktopMode().height / 2) - 390);

	window.create(VideoMode(1500, 700), "Iro And The Light Forest", Style::Titlebar | Style::Close);
	window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);

	MouseDirections md;
	Player player;
	Box BoxArr[5];

	for (int i = 0; i < 5 ;i++)
	{
		BoxArr[i].setter(i * 128, 300);
	}
	

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
	
		//TODO
		//	dir.x++;
		//	if (dir.x * 32 >= texture.getSize().x)
		//	dir.x = 0;



	// TODO 
	//	md.mouseDirections(window, player.getSprite());
	//	md.getRotation(window, player.getSprite());



		for (int i = 0; i < 5; i++)
		{
			BoxArr[i].drawBox(window);
			if (Collision::PixelPerfectTest(player.getSprite(), BoxArr[i].getSprite())) {
				player.collision();
			}
		}
		player.drawPlayer(window);

		
		window.display();
		window.clear();
	}
}