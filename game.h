#pragma once
#include "SFML/Graphics.hpp"
#include "car.h"
#include "road.h"
#include "splash_screen.h"

class Game {
public:
	enum GameState { SPLASH, PLAY, GAME_OVER };
	Game();
	void events_check();
	void update();
	void draw();
	void play();

private:
	GameState game_state = SPLASH;
	sf::RenderWindow window;
	SplashScreen splash;
	Road road1, road2;
	Car car;
};