#include <SFML/Graphics.hpp>
using namespace sf;


int main()
{

	RenderWindow window(sf::VideoMode(800, 600), "SFML works!");



	CircleShape shape(150);
	shape.setPosition(100, 100);
	shape.setFillColor(sf::Color(100, 250, 50));

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}