//
// Created by pedro-souza on 02/10/2025.
//

#pragma once
#include "SDL.h"
#include <GL/glew.h>

extern "C" {
    #include "Network/UdpNet.h"
}

class Game {
public:
    Game();

    bool Initialize();
    void RunLoop();
    void Shutdown();
    void Quit() { mIsRunning = false; }

    static const int WINDOW_WIDTH = 1024;
    static const int WINDOW_HEIGHT = 768;

private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    // SDL stuff
    SDL_Window* mWindow;

    // Game control variables
    Uint32 mTicksCount;
    bool mIsRunning;

    // Network variables and methods
    NetClient mClient;
};
