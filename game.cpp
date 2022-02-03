#include "game.h"
#include "const.h"


Game::Game() {
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	window.create(
		sf::VideoMode(static_cast<size_t>(WINDOW_WIDTH), static_cast<size_t>(WINDOW_HEIGHT)),
		WINDOW_TITLE, 
		sf::Style::Titlebar | sf::Style::Close
	);
	window.setPosition(sf::Vector2i((desktop.width - static_cast<size_t>(WINDOW_WIDTH))/2u, 0));
	window.setVerticalSyncEnabled(true);

	car.init();
	road1.init(0.f,0.f);
	road2.init(0.f, -WINDOW_HEIGHT);
}

void Game::events_check() {
	sf::Event event;
	while (window.pollEvent(event)){
		if (event.type == sf::Event::Closed) 
			window.close();
		if (event.type == sf::Event::KeyPressed) {
			if (game_state == SPLASH && event.key.code == sf::Keyboard::Space) {
				game_state = PLAY;
			}
		}
	}
}

void Game::update() {
	switch (game_state) {
	case SPLASH:
		break;
	case PLAY:
		road1.update();
		road2.update();
		car.update();
		break;
	case GAME_OVER:
		break;
	}
}

void Game::draw() {
	switch (game_state) {
		case SPLASH:
			window.clear(sf::Color::Yellow);
			window.draw(splash.getSprite());
			break;
		case PLAY:
			window.draw(road1.getSprite());
			window.draw(road2.getSprite());
			window.draw(car.getSprite());
			break;
		case GAME_OVER:
			break;
	}
	window.display();
}

void Game::play() {
	while (window.isOpen())
	{
		events_check();
		update();
		draw();
	}
}