#include "tower.h"

Tower::Tower(Engine &engine, Vector2 position) : Entity(engine, position) {
    _target = nullptr;

    if (!_engine.assetServer.textures.count("tex_tower")) {
        _engine.assetServer.ImportTexture("tex_tower", "assets/tower.png");
    }

    _sprite = _engine.assetServer.textures["tex_tower"];
}

void Tower::Think(float delta) {
    if (_fireDelay > 0) {
        _fireDelay -= delta;
    }

    if (_target == nullptr) {
        for (auto pair: _engine.scene->Entities) {
            auto npc = dynamic_cast<NPC *>(pair.second);
            if (npc == nullptr) {
                continue;
            }

            if (Vector2Distance(npc->Position, Position) < _range) {
                _target = npc;
                break;
            }
        }
    }

    if (_target == nullptr) {
        return;
    }

    if (Vector2Distance(_target->Position, Position) > _range) {
        _target = nullptr;
        return;
    }

    if (_fireDelay <= 0) {
        _engine.scene->SpawnEntity(new Projectile(_engine, Position, _target));
        _fireDelay = _fireRate;
    }

    _rotation = Vector2Angle(
            Vector2{0, -1},
            Vector2Subtract(_target->Position, Position)
    ) * 180 / PI;

    _target = nullptr;
}

void Tower::Render(float delta) {
    DrawTexturePro(
            _sprite,
            Rectangle{16, 0, 16, 16},
            Rectangle{Position.x, Position.y, 32, 32},
            Vector2{16, 16},
            0,
            WHITE
    );

    DrawTexturePro(
            _sprite,
            Rectangle{0, 0, 16, 16},
            Rectangle{Position.x, Position.y, 32, 32},
            Vector2{16, 16},
            _rotation,
            WHITE
    );

    DrawCircleLines(Position.x, Position.y, _range, RED);
    if (_target != nullptr) {
        DrawCircleLines(_target->Position.x, _target->Position.y, 20, RED);
    }

    if (_engine.DrawDebugGraphics) {
        DrawText(_target != nullptr ? "Target: Acquired" : "Target: nullptr", Position.x + 20, Position.y + 10, 10,
                 WHITE);
    }
}