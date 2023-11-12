#include "Scene.h"

//added some loading logic for possible scenes according to what I thought would be correct rather than having it blank.
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
    auto& modifiableJson = const_cast<json::JSON&>(json); 

    if (modifiableJson.hasKey("name")) {
        name = modifiableJson["name"].ToString();
        std::cout << "Scene Name: " << name << std::endl;
    }
    if (modifiableJson.hasKey("id")) {
        id = modifiableJson["id"].ToInt();
        std::cout << "Scene ID: " << id << std::endl;
    }
    if (modifiableJson.hasKey("entities")) {
        auto entitiesArray = modifiableJson["entities"].ArrayRange();
        for (auto& entityData : entitiesArray) {
            if (entityData.hasKey("name")) {
                std::string entityName = entityData["name"].ToString();
                std::cout << "Entity Name: " << entityName << std::endl;
            }
            Entity* newEntity = CreateEntity();
            newEntity->Load(entityData);  
        }
    }
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
