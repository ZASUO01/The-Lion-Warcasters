//
// Created by pedro-souza on 02/10/2025.
//
#include "Game.h"

int main(){
    Game game;
    if (game.Initialize()){
        game.RunLoop();
    }
    game.Shutdown();
    return 0;
}