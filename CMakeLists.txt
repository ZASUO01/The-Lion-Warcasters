cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME "projeto-final")
project(${PROJECT_NAME})

find_package(SDL2 2.32.2 EXACT REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME}
        Source/Main.cpp
        Source/Game.cpp
        Source/Game.h
        Source/Network/UdpNet/Client.c
        Source/Network/UdpNet/Client.h
        Source/Network/UdpNet/NetLogger.h
        Source/Network/UdpNet.h
        Source/Network/UdpNet/NetLogger.c
        Source/Network/UdpNet/Socket.c
        Source/Network/UdpNet/Socket.h
        Source/Network/UdpNet/Addrresses.c
        Source/Network/UdpNet/Addrresses.h
        Source/Network/UdpNet/Defs.h
        Source/Network/UdpNet/NetUtils.c
        Source/Network/UdpNet/NetUtils.h
        Source/Network/UdpNet/Platforms.h
        Source/Network/UdpNet/Platforms.c
        Source/Network/UdpNet/Packet.c
        Source/Network/UdpNet/Packet.h
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
)

target_link_libraries(${PROJECT_NAME} PRIVATE GLEW::GLEW SDL2::SDL2 OpenGL::GL)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32)
endif ()