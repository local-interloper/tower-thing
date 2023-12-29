#ifndef PATHFINDER_TOWER_H
#define PATHFINDER_TOWER_H

#include "npc.h"
#include "projectile.h"

class Tower : public Entity {
private:
    NPC *_target;
    Texture2D _sprite;
    float _range = 60;
    float _fireRate = 1;
    float _fireDelay = 0;
    float _rotation = 0;

public:
    Tower(Engine &engine, Vector2 position);

    void Think(float delta) override;

    void Render(float delta) override;
};

#endif //PATHFINDER_TOWER_H
