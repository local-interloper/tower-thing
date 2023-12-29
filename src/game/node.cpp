#include "node.h"
#include "engine.h"

Node::Node(Engine &engine, Vector2 position) : Entity(engine, position), Next(nullptr) {}

void Node::Render(float delta) {
    if(!_engine.DrawDebugGraphics) {
        return;
    }

    if (Next != nullptr) {
        DrawLine(Position.x, Position.y, Next->Position.x, Next->Position.y, WHITE);
    }

    DrawCircle(Position.x, Position.y, 10, RED);
}