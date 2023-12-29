#include "projectile.h"

Projectile::Projectile(Engine &engine, Vector2 position, Entity* target) : Entity(engine, position), _target(target) {}

void Projectile::Think(float delta) {
    if(_target == nullptr) {
        QueueFree();
        return;
    }

    Position = Vector2MoveTowards(Position, _target->Position, _speed);

    if(Vector2Distance(Position, _target->Position) < EPSILON) {
        _target->QueueFree();
        QueueFree();
    }
}

void Projectile::Render(float delta) {
    DrawCircle(Position.x, Position.y, 5, RED);
}