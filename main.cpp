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

	window.create(VideoMode(1920, 1080), "Iro And The Light Forest", Style::Titlebar | Style::Close);
	window.setPosition(centerWindow);
	window.setFramerateLimit(450);
	
	window.setKeyRepeatEnabled(true);

	vector<Bullet> bVector;

	//list
	list<Bullet> bulletList;
    Texture bulletTexture;

	if (bulletTexture.loadFromFile("images/bullet.png")) {
		cout << "bullet.png load failed";
	}

	MouseDirections md;
	Player player;


	Entrance entrance, entrance2;

	entrance.setPosition(0, 0);
	entrance2.setPosition(1056, 0);

	//Main Loop:
	while (window.isOpen()) {

		player.movePlayer();

		
		if (Mouse::isButtonPressed(Mouse::Left)) {
			bulletList.push_front(Bullet(player.getSprite().getPosition().x, player.getSprite().getPosition().y, md.mouseDirections(window, player.getSprite()),&bulletTexture));	
		}
		

	/*------------------------------------------------------Vector---------------------------------------------------------------------------------------
		if (Mouse::isButtonPressed(Mouse::Left)) {

			bVector.push_back(Bullet(player.getSprite().getPosition().x, player.getSprite().getPosition().y, md.mouseDirections(window, player.getSprite())));

			//cout << "bullet z prest" << endl;
			//	cout << "BULLET #" <<  id++ << endl;
		}
	*///------------------------------------------------------Vector-------------------------------------------------------------------------------------- -


		
		if (!(bulletList.empty())) {
			for (std::list<Bullet>::iterator it = bulletList.begin(); it != bulletList.end(); ++it) {
				{
					it->moveBullet(window);
				}
			}
		}
		
			
			
			/*------------------------------------------------------Vector---------------------------------------------------------------------------------------
			if (!(bVector.empty())) {
				for (int i = 0; i < bVector.size(); i++)
				{
					bVector.at(i).moveBullet(window);

					//cout << "bullet z z move" << endl;;
					//	cout << "move " << endl;
				}
			}
			*///------------------------------------------------------Vector---------------------------------------------------------------------------------------


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
			player.drawPlayer(window);

			
			if (!(bulletList.empty())) {
				for (std::list<Bullet>::iterator it = bulletList.begin(); it != bulletList.end(); ++it) {
						it->drawBullet(window);
						/* ------------------------> wypierdolka
						if (it->outOfBounds()) {
							bulletList.pop_back();
						}
						*///-------------------------------------|
				}
			}
			
		/*------------------------------------------------------Vector---------------------------------------------------------------------------------------
			if (!(bVector.empty())) {
				for (int i = 0; i < bVector.size(); i++)
				{
					bVector.at(i).drawBullet(window);
					if (bVector.at(i).outOfBounds()) {
						bVector.pop_back();
					}
				}
			}
		*///------------------------------------------------------Vector---------------------------------------------------------------------------------------



			window.display();
			window.clear();
		}
	}
