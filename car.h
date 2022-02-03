#pragma once
#include "const.h"
#include "SFML/Graphics.hpp"

class Car {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed;
	void move();
	void checkScreenBordersCollision();
public:
	Car();
	void update();
	sf::Sprite getSprite();
	sf::FloatRect getHitBox();
	void init();
};