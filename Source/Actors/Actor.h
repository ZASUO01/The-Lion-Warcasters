// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include <vector>
#include <SDL_stdinc.h>
#include "../Utils/Math.h"
#include "../Renderer/Renderer.h"

enum class ActorState{
    Active,
    Paused,
    Destroy
};

class Actor{
public:
    Actor(class Game* game);
    virtual ~Actor();

    void Update(float deltaTime);
    void ProcessInput(const Uint8* keyState);

    // Position getter/setter
    const Vector2& GetPosition() const { return mPosition; }
    void SetPosition(const Vector2& pos) { mPosition = pos; }

    // Scale getter/setter
    const Vector2& GetScale() const { return mScale; }
    void SetScale(const Vector2& scale) { mScale = scale; }

    // Rotation getter/setter
    float GetRotation() const { return mRotation; }
    void SetRotation(float rotation) { mRotation = rotation; }

    // State getter/setter
    ActorState GetState() const { return mState; }
    void SetState(ActorState state) { mState = state; }

    // Get Forward vector
    Vector2 GetForward() const { return Vector2(Math::Cos(mRotation), Math::Sin(mRotation)); }

    // Model matrix
    Matrix4 GetModelMatrix() const;

    // Game getter
    class Game* GetGame() { return mGame; }

    // Components getter
    //const std::vector<class Component*>& GetComponents() const { return mComponents; }

    // Returns component of type T, or null if doesn't exist
    /*
    template <typename T>
    T* GetComponent() const
    {
        for (auto c : mComponents)
        {
            T* t = dynamic_cast<T*>(c);
            if (t != nullptr)
            {
                return t;
            }
        }

        return nullptr;
    }
    */

protected:
    class Game* mGame;

    virtual void OnUpdate(float deltaTime);
    virtual void OnProcessInput(const Uint8* keyState);

    ActorState mState;

    // Transform
    Vector2 mPosition;
    Vector2 mScale;
    float mRotation;

    // Components
    //std::vector<class Component*> mComponents;

private:
    //friend class Component;

    // Adds component to Actor (this is automatically called
    // in the component constructor)
    //void AddComponent(class Component* c);
};