#include <iostream>
#include <stdlib.h>
#include <list>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Gravity.h"
#include "Box.h"
#include "Bullet.h"
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
	window.setFramerateLimit(360);
	MouseDirections md;
	Player player;

	//bulet
	list<Bullet> bulletList;

	Box BoxArr[5];

	for (int i = 0; i < 5 ;i++)
	{
		BoxArr[i].setter(i * 128, 300);
	}


	int id = 0;


	//Main Loop:
	while (window.isOpen()) {

		player.movePlayer();
		player.considerGravity();

		if (Mouse::isButtonPressed(Mouse::Left)) {
	
			Bullet bullet;
			bulletList.push_front(bullet);
			cout << "BULLET #" <<  id++ << endl;
		}
		
		
		//move bullet
		list<Bullet>::iterator it;
		for (it = bulletList.begin(); it != bulletList.end(); ++it)
		{
			Bullet b = bulletList.front();
			b.moveBullet(window);
		//	cout << "move " << endl;
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
	 
		for (int i = 0; i < 5; i++)
		{
			BoxArr[i].drawBox(window);
			if (Collision::PixelPerfectTest(player.getSprite(), BoxArr[i].getSprite())) {
				player.collision();
			}
		}
		player.drawPlayer(window);
	
		for (it = bulletList.begin(); it != bulletList.end(); ++it)
		{
			Bullet b = bulletList.front();
			b.drawBullet(window);
			//cout << "draw " <<endl; 
			//if (b.outOfBounds)			 BUG tu bedzie sprawdzac czy wylecial poza ekran jesli tak to usuwamy bullet 
			//	bulletList.pop_back();		 BUG
		}		
		window.display();
		window.clear();

	}
}