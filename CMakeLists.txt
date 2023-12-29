cmake_minimum_required(VERSION 3.27)
project(towerthing)

set(CMAKE_CXX_STANDARD 17)

find_library(LIB_RAYLIB raylib)

file(GLOB TOPLEVEL_SRCS src/*.cpp)
file(GLOB ENGINE_SRCS src/engine/*.cpp)
file(GLOB GAME_SRCS src/game/*.cpp)

include_directories(
        src/engine/include
        src/game/include
)

add_executable(
        ${PROJECT_NAME}
        ${TOPLEVEL_SRCS}
        ${ENGINE_SRCS}
        ${GAME_SRCS}
)

target_link_libraries(${PROJECT_NAME} ${LIB_RAYLIB})
