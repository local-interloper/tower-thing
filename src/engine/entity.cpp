#include "entity.h"
#include "engine.h"

Entity::Entity(Engine &engine) : _engine(engine), Position(Vector2Zero()) {}

Entity::Entity(Engine &engine, Vector2 position) : _engine(engine), Position(position) {}

void Entity::Think(float delta) {}

void Entity::Render(float delta) {}

void Entity::SetId(unsigned long int id) {
    _id = id;
}

void Entity::QueueFree() {
    _engine.QueueFree(_id);
}
