#include <string>

#include <SFML/Window.hpp>

#include "gameController/GameLoop.hpp"

int main() {

	std::string str = "Conway";
	std::string str1 = "Rainbow";
	std::string str2 = "High";
	GameLoop game;

	game.gameLoop(str2, 1);

	return 0;
}