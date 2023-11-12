#include "SceneManager.h"

void SceneManager::Initialize()
{
}

void SceneManager::Destroy()
{
}

void SceneManager::Update()
{
}

void SceneManager::AddScene(const std::string& fileName)
{
}

void SceneManager::RemoveScene(const std::string& fileName)
{
}

Entity* SceneManager::CreateEntity()
{
    return nullptr;
}

void SceneManager::RemoveEntity(Entity* entity)
{
}

void SceneManager::SetActiveScene(int id)
{
}

Scene* SceneManager::GetActiveScene() const
{
    return activeScene;
}

Entity* SceneManager::FindEntityById(int id)
{
    return nullptr;
}

