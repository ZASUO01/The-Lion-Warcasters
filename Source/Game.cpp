//
// Created by pedro-souza on 04/11/2025.
//

#include "Game.h"

#include "Network/Packet.h"
#include "Utils/Random.h"
#include <iostream>

Game::Game()
        :mWindow(nullptr)
        ,mRenderer(nullptr)
        ,mTicksCount(0)
        ,mIsRunning(true)
{
}

bool Game::Initialize()
{
    Random::Init();

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    mWindow = SDL_CreateWindow("projeto final", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
    if (!mWindow)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }

    mTicksCount = SDL_GetTicks();

    typedef struct GameState {
        int a;
        bool b;
        double c;
    };

    GameState gameState;
    gameState.a = 2;
    gameState.b = true;
    gameState.c = 0.35;

    Packet p(0, Packet::ACK_FLAG, 0);
    p.SetData(&gameState, sizeof(gameState));
    p.BuildPacket();

    if (!p.IsValid()) {
        std::cout << "invalid\n";
    }

    std::cout<< "valid\n";

    const auto gameState2 = static_cast<const GameState *>(p.GetData());

    std::cout << gameState2->a << " / " << gameState2->b << " / " << gameState2->c << "\n";

    return true;
}

void Game::RunLoop()
{
    while (mIsRunning)
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::ProcessInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                Quit();
                break;
            default:
                break;
        }
    }

    const Uint8* state = SDL_GetKeyboardState(nullptr);
}

void Game::UpdateGame()
{
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16)) {}

    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
    if (deltaTime > 0.05f){
        deltaTime = 0.05f;
    }

    mTicksCount = SDL_GetTicks();
}

void Game::GenerateOutput(){}

void Game::Shutdown()
{
    mRenderer = nullptr;

    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}