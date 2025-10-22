//
// Created by pedro-souza on 02/10/2025.
//
#include "Game.h"
#include "Network/Platforms.h"

int main(){
    if (Platforms::platformNetworkingInit() != 0) {
        exit(EXIT_FAILURE);
    }

    Game game;
    if (game.Initialize()){
        game.RunLoop();
    }
    game.Shutdown();

    Platforms::platformNetworkingCleanup();
    return 0;
}