#ifndef PATHFINDER_NODE_H
#define PATHFINDER_NODE_H

#include <vector>
#include <raylib.h>
#include "entity.h"

using std::vector;

class Node : public Entity {
public:
    Node(Engine &engine, Vector2 position);

    Node *Next;

    void Render(float delta) override;
};

#endif //PATHFINDER_NODE_H
