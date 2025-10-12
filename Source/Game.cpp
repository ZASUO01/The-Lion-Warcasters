//
// Created by pedro-souza on 02/10/2025.
//

#include "Game.h"

#include "Network/UdpNet/Packet.h"
#include "Network/UdpNet/Socket.h"
#include "Utils/Random.h"

Game::Game()
        :mWindow(nullptr)
        ,mRenderer(nullptr)
        ,mTicksCount(0)
        ,mIsRunning(true)
{
    init_net_client(&mClient);
    add_server_addr(&mClient, "127.0.0.1");
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

    mRenderer = new Renderer(mWindow);
    mRenderer->Initialize(Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT);

    mTicksCount = SDL_GetTicks();

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
        }
    }

    const Uint8* state = SDL_GetKeyboardState(nullptr);

    UdpNetPacket pk;
    init_packet(&pk, 0, SYN_FLAG, 0);
    build_packet(&pk);
    size_t pk_size = PACKET_HEADER_BYTES;
    send_packet_to_v4(mClient.socket, &pk, pk_size, &mClient.server_addr_v4);
}

void Game::UpdateGame()
{
    bool packet_received = false;
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16)) {
        if (socket_ready_to_receive(mClient.socket , 0) != 0) {
            continue;
        }

        UdpNetPacket pk;
        if (receive_packet_from_v4(mClient.socket, &pk, &mClient.server_addr_v4) != 0) {
            continue;
        }

        SDL_Log("reveived packet");
    }

    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
    if (deltaTime > 0.05f)
    {
        deltaTime = 0.05f;
    }

    mTicksCount = SDL_GetTicks();
}

void Game::GenerateOutput()
{
    mRenderer->Clear();

    mRenderer->Present();
}

void Game::Shutdown()
{
    close_client(&mClient);

    mRenderer->Shutdown();
    delete mRenderer;
    mRenderer = nullptr;

    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}