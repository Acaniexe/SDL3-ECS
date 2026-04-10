#pragma once
#include "entity_manager.h"
#include "components/position.h"
#include "components/velocity.h"

// System responsible for updating the positions of entities based on their velocities.
class MovementSystem {
public:
    void update(EntityManager& entityManager, double deltaTime) {
        // Iterate through all entities in the manager
        for (auto& [entityId, components] : entityManager.getEntities()) {
            auto* position = entityManager.getComponent<Position>(Entity(entityId));
            auto* velocity = entityManager.getComponent<Velocity>(Entity(entityId));

            if (position && velocity) {
                position->x += velocity->dx * deltaTime;
                position->y += velocity->dy * deltaTime;
            }
        }
    }
};