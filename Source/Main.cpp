//
// Created by pedro-souza on 04/11/2025.
//

#include "Game.h"
#include "Network/Platforms.h"
#undef main

int main() {
    networkingInit();

    Game game;
    if (game.Initialize()){
        game.RunLoop();
    }
    game.Shutdown();

    networkingCleanup();
    return 0;
}
