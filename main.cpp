#include <string>

#include <SFML/Window.hpp>

#include "gameController/GameLoop.hpp"
#include "Menu/Menu.hpp"


int main() {
	Menu menu;
	menu.run();
	int mode = menu.get_player();
	int player = menu.get_mode();

	std::string str = "Conway";
	std::string str1 = "Rainbow";
	std::string str2 = "High";
	GameLoop game;
	std::cout << player << std::endl;
	if(mode == 1){
		game.gameLoop(str, player);
	}
	else if(mode == 2){
		game.gameLoop(str1, player);
	}
	else if(mode == 3){
		game.gameLoop(str2, player);
	}


	return 0;
}