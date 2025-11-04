//
// Created by pedro-souza on 04/11/2025.
//
#undef main
#include "Game.h"

int main() {
    Game game;
    if (game.Initialize()){
        game.RunLoop();
    }
    game.Shutdown();
    return 0;
}