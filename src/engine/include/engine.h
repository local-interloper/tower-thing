#ifndef OGRESBOX_ENGINE_H
#define OGRESBOX_ENGINE_H

#include <map>
#include <ctime>
#include <queue>
#include <raylib.h>
#include <raymath.h>
#include "entity.h"
#include "scene.h"
#include "asset_server.h"

using std::map;
using std::queue;

class Engine {

public:
    Scene *activeScene;
    AssetServer assetServer;

    bool DrawDebugGraphics = false;

    void Start();

    void Mainloop();

    void Render();

    void Think();

    void SpawnEntity(Entity *entity);
    void QueueFree(unsigned long int id) const;

    void FreeQueued() const;
};

#endif //OGRESBOX_ENGINE_H
