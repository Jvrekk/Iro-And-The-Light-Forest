#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <list>
#include "Gravity.h"
#include "Box.h"
#include "Bullet.h"
#include "Collision.h"
#include "MouseDirections.h"
#include "entrance.h"
#include <vector>


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

	vector<Bullet> bVector; 


	MouseDirections md;
	Player player;
	

	Entrance entrance,entrance2;

	entrance.setPosition(0, 0);
	entrance2.setPosition(1056, 0);



	//Main Loop:
	while (window.isOpen()) {

		player.movePlayer();
		
		
		if (Mouse::isButtonPressed(Mouse::Left)) {

			bVector.push_back(Bullet(player.getSprite().getPosition().x, player.getSprite().getPosition().y));

			//cout << "bullet z prest" << endl;
			//	cout << "BULLET #" <<  id++ << endl;
		} 


		
		if (!(bVector.empty())) {
			for (int i = 0; i < bVector.size(); i++)
			{
				try
				{
					bVector.at(i).moveBullet(window);
				}
				catch (const std::exception&)
				{
					cout << endl << " exception moveBullet " << endl;
					system("pause");
				}

				//cout << "bullet z z move" << endl;;
				//	cout << "move " << endl;
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
		
		
		if (!(bVector.empty())) {
			for (int i = 0; i < bVector.size(); i++)
			{
				bVector.at(i).drawBullet(window);
			}
		}
	
		
	
		window.display();
		window.clear();
	}
}
