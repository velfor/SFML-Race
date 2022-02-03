#include <SFML/Graphics.hpp>
#include "const.h"
#include "game.h"
using namespace sf;
int main()
{
	Game *game = new Game();
	game->play();
	return 0;
}