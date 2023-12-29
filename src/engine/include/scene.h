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

    virtual void Think();

    virtual void Render();

    void SpawnEntity(Entity *entity);
};

#endif //PATHFINDER_SCENE_H
