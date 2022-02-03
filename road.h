#pragma once
#include "const.h"
#include "SFML/Graphics.hpp"

class Road {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed;
public:
	Road();
	void update();
	sf::Sprite getSprite();
	void init(float, float);
	sf::FloatRect getHitBox();
};