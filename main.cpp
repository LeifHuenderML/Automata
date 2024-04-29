#include <string>
#include <thread>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "gameController/GameLoop.hpp"
#include "Menu/Menu.hpp"

void playMusic(sf::SoundBuffer& buffer);

int main(){
    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile("music/lofi.wav")){
        std::cerr << "Could not load music file." << std::endl;
        return -1;  
    }

    std::thread musicThread(playMusic, std::ref(buffer));

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
    } else if(mode == 2){
        game.gameLoop(str1, player);
    } else if(mode == 3){
        game.gameLoop(str2, player);
    }

    musicThread.join();

    return 0;
}

void playMusic(sf::SoundBuffer& buffer){
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setLoop(true);
    sound.play();

    while(sound.getStatus() == sf::Sound::Playing){
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
