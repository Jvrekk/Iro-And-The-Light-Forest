#include "Animations.h"

Animations::Animations(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) {

	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);

}
Animations::Animations() {};

Animations::~Animations()
{
}

void Animations::Update(int row, float deltaTime, bool faceRight) {
	currentImage.y = row;
	totalTime += deltaTime;
	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x) {
			currentImage.x = 0;
		}
	}

	uvRect.top = currentImage.y * uvRect.height;

	if (faceRight) {
		currentImage.y = row;
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else {
		currentImage.y = row ;
		uvRect.left = (currentImage.x) * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
}