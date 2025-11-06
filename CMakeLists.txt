cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME "the-lion-warcasters")
project(${PROJECT_NAME})

find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME}
        Source/Main.cpp
        Source/Main.cpp
        Source/Game.cpp
        Source/Game.h
        Source/Utils/Math.cpp
        Source/Utils/Math.h
        Source/Utils/Random.cpp
        Source/Utils/Random.h
        Source/Network/Platforms.cpp
        Source/Network/Platforms.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE GLEW::GLEW SDL2::SDL2 OpenGL::GL)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32)
endif ()