#pragma once

#include <list>
#include <string>
#include "Entity.h"

class Scene
{
private:
    std::list<Entity*> entities;
    std::string name;
    int id;

public:
    Scene();
    ~Scene();

    void Initialize();
    void Destroy();
    void Update();
    void Load(const JSON& json);

    Entity* CreateEntity();
    void RemoveEntity(Entity* _entity);
    Entity* FindEntityById(int id);
};
