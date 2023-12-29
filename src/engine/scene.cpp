#include "scene.h"
#include <iostream>

Scene::Scene(Engine &engine) : _engine(engine) {}

void Scene::Init() {}

void Scene::Think(float delta) {
    for(auto& pair : Entities) {
        pair.second->Think(delta);
    }
}

void Scene::Render(float delta) {
    for(auto& pair : Entities) {
        pair.second->Render(delta);
    }
}

void Scene::SpawnEntity(Entity *entity) {
    entity->SetId(EntIndex);
    Entities.emplace(EntIndex, entity);
    EntIndex++;
}

void Scene::QueueFree(unsigned long id){
    FreeQueue.push(id);
}

void Scene::FreeQueued() {
    while (!FreeQueue.empty()) {
        unsigned long int id = FreeQueue.front();
        delete Entities[id];
        Entities[id] = nullptr;
        Entities.erase(id);
        FreeQueue.pop();
    }
}
