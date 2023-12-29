#include <asset_server.h>

AssetServer::AssetServer() {
    textures = map<string, Texture2D>();
}

void AssetServer::ImportTexture(const std::string &name, const std::string path) {
    textures[name] = LoadTexture(path.c_str());
}