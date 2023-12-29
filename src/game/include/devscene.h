#ifndef PATHFINDER_DEVSCENE_H
#define PATHFINDER_DEVSCENE_H

#include <vector>
#include "node.h"
#include "scene.h"

using std::vector;

class Devscene : public Scene {
private:
    Texture2D _backgroundTexture;
    vector<Node *> _nodes;

public:
    Devscene(Engine &engine);

    void Init() override;

    void Render() override;

    void Think() override;
};

#endif //PATHFINDER_DEVSCENE_H
