#pragma once
#include "SFML/Graphics.hpp"

class SplashScreen {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	SplashScreen() {
		texture.loadFromFile("race-splash.png");
		sprite.setTexture(texture);
	}
	sf::Sprite getSprite() { return sprite; }
};
