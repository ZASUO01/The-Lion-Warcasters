//
// Created by pedro-souza on 04/11/2025.
//

#pragma once
#include <SDL.h>
#include "Network/Client.h"

class Game {
public:
    Game();

    bool Initialize();
    void RunLoop();
    void Shutdown();
    void Quit() { mIsRunning = false; }

    [[nodiscard]] class Renderer* GetRenderer() const { return mRenderer; }

    static constexpr int WINDOW_WIDTH = 1024;
    static constexpr int WINDOW_HEIGHT = 768;

private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    // SDL stuff
    SDL_Window* mWindow;
    class Renderer *mRenderer;

    // Game control variables
    Uint32 mTicksCount;
    bool mIsRunning;

    //Network
    Client* mClient;
};