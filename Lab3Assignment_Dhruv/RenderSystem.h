#pragma once

#include <string>
#include <list>
#include "IRenderable.h"

class RenderSystem
{
private:
    std::string name = "Game";
    unsigned int width = 1280;
    unsigned int height = 720;
    bool fullScreen = false;
    std::list<IRenderable*> renderables;

public:
    static RenderSystem& Instance()
    {
        static RenderSystem instance;
        return instance;
    }

    void AddRenderable(IRenderable* renderable);
    void RemoveRenderable(IRenderable* renderable);

    void Initialize();
    void Update();
    void Destroy();
    void Load();

private:
    RenderSystem() = default;
    ~RenderSystem() = default;
    RenderSystem(const RenderSystem&) = delete;
    RenderSystem& operator=(const RenderSystem&) = delete;
};
