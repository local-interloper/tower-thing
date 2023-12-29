#include "engine.h"
#include "node.h"
#include "scene.h"
#include "devscene.h"
#include <iostream>

void Engine::Start() {
    InitWindow(600, 600, "pathfinder");
    SetTargetFPS(60);

    // SETUP
    activeScene = new Devscene(*this);
    activeScene->Init();
    // SETUP

    Mainloop();
}

void Engine::Mainloop() {
    while (!WindowShouldClose()) {
        Render();
        Think();
        FreeQueued();
    }
}

void Engine::Think() {
    if (IsKeyPressed(KEY_F3)) {
        DrawDebugGraphics = !DrawDebugGraphics;
    }

    activeScene->Think();
}

void Engine::Render() {
    BeginDrawing();
    ClearBackground(BLACK);
    activeScene->Render();
    DrawText("pathfinder", 5, 5, 15, WHITE);
    if (DrawDebugGraphics) {
        DrawText("[Debug Graphics]", 5, 25, 15, WHITE);
    }
    EndDrawing();
}

void Engine::QueueFree(unsigned long id) const {
    activeScene->FreeQueue.push(id);
}

void Engine::FreeQueued() const {
    while (!activeScene->FreeQueue.empty()) {
        unsigned long int id = activeScene->FreeQueue.front();
        delete activeScene->Entities[id];
        activeScene->Entities[id] = nullptr;
        activeScene->Entities.erase(id);
        activeScene->FreeQueue.pop();
    }
}