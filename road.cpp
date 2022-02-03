#include "road.h"

Road::Road() {
	texture.loadFromFile("road.jpg");
	texture.setSmooth(true);
	sprite.setTexture(texture);
	
}
void Road::update() {
	sprite.move(0, 2.f);
	sf::Vector2f current_position = sprite.getPosition();
	sf::Vector2f size = sf::Vector2f(getHitBox().width, getHitBox().height);
	if (current_position.y >= WINDOW_HEIGHT) {
		sprite.setPosition(0, -1.0 * WINDOW_HEIGHT);
	}
}
sf::Sprite Road::getSprite() { return sprite; }
void Road::init(float startx, float starty) {
	sf::Vector2f size = sf::Vector2f(getHitBox().width, getHitBox().height);
	sf::Vector2f scale = sf::Vector2f(WINDOW_WIDTH / size.x, WINDOW_HEIGHT / size.y);
	sprite.setScale(scale);
	sprite.setPosition(startx, starty);
}
sf::FloatRect Road::getHitBox() { return sprite.getGlobalBounds(); }