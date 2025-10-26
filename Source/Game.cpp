//
// Created by pedro-souza on 02/10/2025.
//

#include "Game.h"
#include "Actors/Actor.h"
#include "Network/Packet.h"
#include "Network/Socket.h"
#include "Utils/Random.h"
#include <iostream>

Game::Game()
        :mWindow(nullptr)
        ,mRenderer(nullptr)
        ,mTicksCount(0)
        ,mIsRunning(true)
{
    mClient = new NetClient();
    mClient->Init();
    mClient->SetServerAddrV4("127.0.0.1");
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

    Actor *actor = new Actor(this);

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
            default:
                break;
        }
    }

    const Uint8* state = SDL_GetKeyboardState(nullptr);
}

void Game::UpdateGame()
{
    // Send Packet
    SendDataToServer();

    bool packetReceived = false;
    NetPacket res;

    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16)) {
        if (!packetReceived) {
            if (!SocketUtils::socketReadyToReceive(mClient->GetSocket(), 0)) {
                continue;
            }

            if (!SocketUtils::receivePacketFromV4(mClient->GetSocket(), &res, &mClient->GetServerAddrV4())) {
                continue;
            }

            if (!res.IsValid()) {
                continue;
            }

            auto fields = res.GetFields();
            std::cout << fields[0].GetValue<std::string>() << "\n";
        }
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
    mClient->Close();
    delete mClient;

    mRenderer->Shutdown();
    delete mRenderer;
    mRenderer = nullptr;

    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Game::SendDataToServer() const {
    NetPacket pk(0, NetPacket::DATA_FLAG,mClient->GetNonce());
    const DataField data("Hello server");
    pk.AddField(data);
    pk.BuildPacket();
    const size_t pkSize = NetPacket::PACKET_HEADER_BYTES + pk.GetLength();

    SocketUtils::sendPacketToV4(
        mClient->GetSocket(),
        &pk,
        pkSize,
        &mClient->GetServerAddrV4()
    );
}
