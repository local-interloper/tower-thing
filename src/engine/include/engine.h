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
    Scene *scene;
    AssetServer assetServer;

    bool DrawDebugGraphics = false;

    void Start();

    void Mainloop();

    void Render(float delta);

    void Think(float delta);

    void QueueFree(unsigned long int id);
};

#endif //OGRESBOX_ENGINE_H
