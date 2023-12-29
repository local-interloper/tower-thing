#ifndef PATHFINDER_ENTITY_H
#define PATHFINDER_ENTITY_H

#include <raylib.h>
#include <raymath.h>
class Engine;

class Entity {
protected:
    unsigned long int _id;
    Engine &_engine;

public:
    explicit Entity(Engine &engine);
    Entity(Engine &engine, Vector2 position);

    Vector2 Position;

    virtual void Think(float delta);

    virtual void Render(float delta);

    void SetId(unsigned long int id);

    void QueueFree();
};


#endif //PATHFINDER_ENTITY_H
