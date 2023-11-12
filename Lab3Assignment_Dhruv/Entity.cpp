#include "Entity.h"
#include <iostream>

Entity::Entity()
{
}

Entity::~Entity()
{
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
    std::cout << "Entity is Destroyed" << std::endl;
    for (auto component : components)
    {
        delete component;
    }
    components.clear();
}

void Entity::Load(const JSON& json)
{
}

Component* Entity::CreateComponent(const std::string& componentType)
{
}
