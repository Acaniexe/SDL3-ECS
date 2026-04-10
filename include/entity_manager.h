#pragma once
#include <unordered_map>
#include <typeindex>

class Entity {
public:
     int id;
     Entity(int id) : id(id) {}
};

// Provides methods to create entities, add components to them, and retrieve components.
class EntityManager {
private:
    int nextEntityId = 0;  // Counter for generating unique entity IDs
    // Storage: entity ID -> (component type -> component pointer)
    std::unordered_map<int, std::unordered_map<std::type_index, void*>> entities;

public:
    // Creates a new entity with a unique ID and returns it.
    Entity createEntity() {
        Entity entity(nextEntityId++);
        return entity;
    }

    // Adds a component to the given entity, The component is copied and stored in the entity's component map.
    template<typename Component>
    void addComponent(Entity& entity, Component component) {
        entities[entity.id][std::type_index(typeid(Component))] = new Component(component);
    }

    // Retrieves a component from the given entity, Returns a pointer if it exists, otherwise nullptr.
    template<typename Component>
    Component* getComponent(const Entity& entity) {
        auto it = entities[entity.id].find(std::type_index(typeid(Component)));
        if (it != entities[entity.id].end()) {
            return static_cast<Component*>(it->second);
        }
        return nullptr;
    }

    // Use this to loop through all entities and their components.
    auto& getEntities() {
        return entities;
    }
};