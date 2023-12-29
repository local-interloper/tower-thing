#include "engine.h"
#include "node.h"
#include "scene.h"
#include "devscene.h"
#include <iostream>

void Engine::Start() {
    InitWindow(600, 600, "pathfinder");
    SetTargetFPS(60);

    // SETUP
    scene = new Devscene(*this);
    scene->Init();
    // SETUP

    Mainloop();
}

void Engine::Mainloop() {
    while (!WindowShouldClose()) {
        float delta = GetFrameTime();
        Render(delta);
        Think(delta);

        if (scene != nullptr) {
            scene->FreeQueued();
        }
    }
}

void Engine::Think(float delta) {
    if (IsKeyPressed(KEY_F3)) {
        DrawDebugGraphics = !DrawDebugGraphics;
    }

    scene->Think(delta);
}

void Engine::Render(float delta) {
    BeginDrawing();
    ClearBackground(BLACK);
    scene->Render(delta);
    DrawText("pathfinder", 5, 5, 15, WHITE);
    if (DrawDebugGraphics) {
        DrawText("[Debug Graphics]", 5, 25, 15, WHITE);
    }
    EndDrawing();
}

void Engine::QueueFree(unsigned long int id) {
    if (scene == nullptr) {
        return;
    }

    scene->QueueFree(id);
}

