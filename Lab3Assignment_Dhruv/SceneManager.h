#pragma once

#include <list>
#include <string>
#include "Scene.h"
#include "Entity.h"

class SceneManager
{
public:
    static SceneManager& Instance()
    {
        static SceneManager instance;
        return instance;
    }

    void Initialize();
    void Destroy();
    void Update();

    void AddScene(const std::string& fileName);
    void RemoveScene(const std::string& fileName);
    Entity* CreateEntity();
    void RemoveEntity(Entity* entity);
    void SetActiveScene(int id);
    Scene* GetActiveScene() const;
    Entity* FindEntityById(int id);

private:
    SceneManager() = default;
    ~SceneManager() = default;
    SceneManager(const SceneManager&) = delete;
    SceneManager& operator=(const SceneManager&) = delete;

    std::list<Scene*> scenes;
    Scene* activeScene = nullptr;
};
