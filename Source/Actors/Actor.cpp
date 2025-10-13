#include "Actor.h"
#include "../Game.h"
#include <algorithm>

Actor::Actor(Game* game)
        : mState(ActorState::Active)
        , mPosition(Vector2::Zero)
        , mScale(Vector2(1.0f, 1.0f))
        , mRotation(0.0f)
        , mGame(game)
{

}

Actor::~Actor()
{

}

void Actor::Update(float deltaTime){}

void Actor::OnUpdate(float deltaTime){}

void Actor::ProcessInput(const Uint8* keyState){}

void Actor::OnProcessInput(const Uint8* keyState){}


Matrix4 Actor::GetModelMatrix() const
{
    Matrix4 scaleMat = Matrix4::CreateScale(mScale.x, mScale.y, 1.0f);
    Matrix4 rotMat   = Matrix4::CreateRotationZ(mRotation);
    Matrix4 transMat = Matrix4::CreateTranslation(Vector3(mPosition.x, mPosition.y, 0.0f));
    return scaleMat * rotMat * transMat;
}