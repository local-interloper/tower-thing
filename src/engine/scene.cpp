#include "scene.h"
#include <iostream>

Scene::Scene(Engine &engine) : _engine(engine) {}

void Scene::Init() {}

void Scene::Think() {
    for(auto& pair : Entities) {
        pair.second->Think();
    }
}

void Scene::Render() {
    for(auto& pair : Entities) {
        pair.second->Render();
    }
}

void Scene::SpawnEntity(Entity *entity) {
    entity->SetId(EntIndex);
    Entities.emplace(EntIndex, entity);
    EntIndex++;
}