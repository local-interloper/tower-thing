#ifndef PATHFINDER_SCENE_H
#define PATHFINDER_SCENE_H

#include <queue>
#include <map>
#include "entity.h"

using std::map, std::queue;

class Engine;

class Scene {
protected:
    Engine &_engine;

public:
    int EntIndex = 0;
    map<unsigned long int, Entity *> Entities = map<unsigned long int, Entity *>();
    queue<unsigned long int> FreeQueue = queue<unsigned long int>();

    explicit Scene(Engine &engine);

    virtual void Init();

    virtual void Think(float delta);

    virtual void Render(float delta);

    void SpawnEntity(Entity *entity);

    void QueueFree(unsigned long int id);

    void FreeQueued();
};

#endif //PATHFINDER_SCENE_H
