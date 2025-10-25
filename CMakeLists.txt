cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME "projeto-final")
project(${PROJECT_NAME})

find_package(SDL2 2.32.2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME}
        Source/Main.cpp
        Source/Game.cpp
        Source/Game.h
        Source/Utils/Math.h
        Source/Utils/Math.cpp
        Source/Utils/Random.h
        Source/Utils/Random.cpp
        Source/Renderer/Shader.cpp
        Source/Renderer/Shader.h
        Source/Renderer/Renderer.cpp
        Source/Renderer/Renderer.h
        Source/Renderer/VertexArray.cpp
        Source/Renderer/VertexArray.h
        Source/Actors/Actor.cpp
        Source/Actors/Actor.h
        Source/Network/Platforms.cpp
        Source/Network/Platforms.h
        Source/Network/Client.cpp
        Source/Network/Client.h
        Source/Network/Socket.cpp
        Source/Network/Socket.h
        Source/Network/NetLogger.cpp
        Source/Network/NetLogger.h
        Source/Network/NetUtils.cpp
        Source/Network/NetUtils.h
        Source/Network/Addresses.cpp
        Source/Network/Addresses.h
        Source/Network/Defs.h
        Source/Network/Packet.cpp
        Source/Network/Packet.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE GLEW::GLEW SDL2::SDL2 OpenGL::GL)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32)
endif ()