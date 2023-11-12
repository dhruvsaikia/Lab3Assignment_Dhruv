#include "SceneManager.h"

//added possible loading logic based on what I thought would be right rather than leaving it blank

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
    for (auto* scene : scenes) {
        if (scene->GetID() == id) {
            activeScene = scene;
            std::cout << "Active scene set to ID: " << id << std::endl;
            break;
        }
    }
}


Scene* SceneManager::GetActiveScene() const
{
    return activeScene;
}

Entity* SceneManager::FindEntityById(int id)
{
    if (activeScene) {
        return activeScene->FindEntityById(id);
    }
    return nullptr;
}
