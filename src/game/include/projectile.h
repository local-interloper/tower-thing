#ifndef PATHFINDER_PROJECTILE_H
#define PATHFINDER_PROJECTILE_H

#include "engine.h"
#include "entity.h"

class Projectile : public Entity {
private:
    Entity *_target;
    float _speed = 5;

public:
    Projectile(Engine& engine, Vector2 position, Entity *target);

    void Think(float delta) override;
    void Render(float delta) override;
};

#endif //PATHFINDER_PROJECTILE_H
