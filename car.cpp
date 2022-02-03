#include "car.h"

Car::Car() {
	texture.loadFromFile("racing-car.png");
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(CAR_SCALE, CAR_SCALE);
	sprite.setRotation(-90.f);
}
void Car::init() {
	sprite.setPosition(
		(WINDOW_WIDTH - getHitBox().width) / 2,
		WINDOW_HEIGHT - CAR_OFFSET_Y
	);
}
void Car::move(){
	speed = sf::Vector2f(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		speed = sf::Vector2f(-CAR_SPEEDX, CAR_SPEEDY);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		speed = sf::Vector2f(CAR_SPEEDX, CAR_SPEEDY);
	}
	sprite.move(speed);
}
void Car::checkScreenBordersCollision() {
	sf::Vector2f current_position = sprite.getPosition();
	sf::Vector2f size = sf::Vector2f(getHitBox().width, getHitBox().height);
	if (current_position.x <= 0) {
		sprite.setPosition(0, current_position.y);
	}
	if (current_position.x >= WINDOW_WIDTH - size.x) {
		sprite.setPosition(WINDOW_WIDTH - size.x, current_position.y);
	}
}
void Car::update() {
	move();
	checkScreenBordersCollision();
}
sf::Sprite Car::getSprite() { return sprite; }
sf::FloatRect Car::getHitBox() { return sprite.getGlobalBounds(); }
