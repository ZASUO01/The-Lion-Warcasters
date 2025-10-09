//
// Created by pedro-souza on 02/10/2025.
//
#include "Game.h"
#include "Network/UdpNet/Platforms.h"

int main(){
    if (platform_networking_init() != 0) {
        exit(EXIT_FAILURE);
    }

    Game game;
    if (game.Initialize()){
        game.RunLoop();
    }
    game.Shutdown();

    platform_networking_cleanup();
    return 0;
}