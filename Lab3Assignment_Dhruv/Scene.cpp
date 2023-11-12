#include "Scene.h"

Scene::Scene() : id(0)
{
}

Scene::~Scene()
{
}

void Scene::Initialize()
{
}

void Scene::Destroy()
{
    for (auto& entity : entities)
    {
        delete entity;
    }
    entities.clear();
}

void Scene::Update()
{
    for (auto& entity : entities)
    {
        entity->Update();
    }
}

void Scene::Load(const json::JSON& json)
{
}

Entity* Scene::CreateEntity()
{
    Entity* newEntity = new Entity();
    entities.push_back(newEntity);
    return newEntity;
}

void Scene::RemoveEntity(Entity* _entity)
{
    entities.remove(_entity);
    delete _entity;
}

Entity* Scene::FindEntityById(int id)
{
    for (auto& entity : entities)
    {
        if (entity->GetId() == id)
            return entity;
    }
    return nullptr;
}
