#include "Entity.h"
#include <iostream>

Entity::Entity()
{
    // Constructor implementation
}

Entity::~Entity()
{
    // Destructor implementation
    std::cout << "Entity is Destroyed" << std::endl;
    for (auto component : components)
    {
        delete component;
    }
    components.clear();
}

void Entity::Initialize()
{
}

void Entity::Update()
{
    for (auto component : components)
    {
        component->Update();
    }
}

void Entity::Destroy()
{
}

void Entity::Load(const json::JSON& json)
{
}

Component* Entity::CreateComponent(const std::string& componentType)
{
    return nullptr;
}
