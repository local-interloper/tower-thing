#ifndef PATHFINDER_ASSET_SERVER_H
#define PATHFINDER_ASSET_SERVER_H

#include <string>
#include <raylib.h>
#include <map>

using std::map, std::string;

class AssetServer {
public:
    AssetServer();

    map<string, Texture2D> textures;

    void ImportTexture(const string &name, std::string path);
};

#endif //PATHFINDER_ASSET_SERVER_H
