#pragma once

#include "Object.h"
#include "Component.h"
#include "json.hpp"  
#include <list>
#include <string>

class Entity final : public Object
{
private:
    std::list<Component*> components;

public:
    Entity();
    ~Entity();

    void Initialize() override;
    void Update();
    void Destroy() override;

    void AddComponent(Component* _component);
    void RemoveComponent(Component* _component);
    void Load(const json::JSON& json) override;
    Component* CreateComponent(const std::string& componentType);
};
