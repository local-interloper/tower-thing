#include "devscene.h"
#include "npc.h"
#include "node.h"
#include "tower.h"
#include <vector>

using std::vector;

Devscene::Devscene(Engine &engine) : Scene(engine) {}

void Devscene::Init() {
    _engine.assetServer.ImportTexture("tex_map", "assets/map.png");
    _backgroundTexture = _engine.assetServer.textures["tex_map"];

    _nodes = vector<Node *>(
            {
                    new Node(_engine, Vector2{520, 70}),
                    new Node(_engine, Vector2{510, 430}),
                    new Node(_engine, Vector2{490, 470}),
                    new Node(_engine, Vector2{360, 470}),
                    new Node(_engine, Vector2{340, 300}),
                    new Node(_engine, Vector2{355, 120}),
                    new Node(_engine, Vector2{320, 80}),
                    new Node(_engine, Vector2{60, 80}),
                    new Node(_engine, Vector2{40, 100}),
                    new Node(_engine, Vector2{40, 180}),
                    new Node(_engine, Vector2{170, 180}),
                    new Node(_engine, Vector2{180, 510}),
            }
    );


    for (int i = 0; i < _nodes.size(); i++) {
        if (i == _nodes.size() - 1) {
            break;
        }

        _nodes[i]->Next = _nodes[i + 1];
    }

    for (auto node: _nodes) {
        SpawnEntity(node);
    }

}

void Devscene::Render() {
    DrawTextureEx(_backgroundTexture, Vector2{0, 0}, 0, 4, WHITE);
    Scene::Render();
}

void Devscene::Think() {
    if (IsKeyPressed(KEY_S)) {
        SpawnEntity(new NPC(_engine, _nodes[0]));
    }

    if(IsKeyPressed(KEY_T)) {
        Vector2 pos = GetMousePosition();
        SpawnEntity(new Tower(_engine, pos));
    }

    Scene::Think();
}