#pragma once
#include <SFML\Graphics.hpp>
class Animations{
public:
	Animations(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	Animations();
	~Animations();
	void Update(int row, float deltaTime, bool faceRight);  

public:
	sf::IntRect uvRect;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime; 
};