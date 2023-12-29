#ifndef PATHFINDER_NPC_H
#define PATHFINDER_NPC_H

#include "entity.h"
#include "engine.h"
#include "node.h"

class NPC : public Entity {
private:
    Texture2D _sprite;
    double _rotation = 0;
    const Node *_target;
    float _step = 1;
public:
    NPC(Engine &engine, Node* spawn);

    void Think(float delta) override;

    void Render(float delta) override;
};

#endif //PATHFINDER_NPC_H
