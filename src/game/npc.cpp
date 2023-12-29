#include "npc.h"

NPC::NPC(Engine &engine, Node *spawn) : Entity(engine), _target(spawn) {
    if (!_engine.assetServer.textures.count("tex_bug")) {
        _engine.assetServer.ImportTexture("tex_bug", "assets/bug.png");
    }
    _sprite = _engine.assetServer.textures["tex_bug"];
    Position = spawn->Position;
    _target = spawn->Next;
}

void NPC::Think() {
    if (Vector2Distance(Position, _target->Position) < _step) {
        if (_target->Next == nullptr) {
            QueueFree();
            return;
        }

        _target = _target->Next;
    }

    Position = Vector2MoveTowards(Position, _target->Position, _step);
    _rotation = Vector2Angle(
            Vector2{0, -1},
            Vector2Subtract(_target->Position, Position)
    ) * 180.0 / PI;
}


void NPC::Render() {
    DrawTexturePro(
            _sprite,
            Rectangle{0, 0, 16, 16},
            Rectangle{Position.x, Position.y, 16, 16},
            Vector2{8, 8},
            (float)_rotation,
            WHITE
    );
}