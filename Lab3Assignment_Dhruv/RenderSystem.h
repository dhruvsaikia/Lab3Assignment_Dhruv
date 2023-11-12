#pragma once

#include <string>
#include <list>
#include "IRenderable.h"
#include "json.hpp" 
#include "SDL.h"

class RenderSystem
{

    //added default values here to be safe and then overwrote them with the json files
private:
    std::string name = "Game";
    unsigned int width = 1240;
    unsigned int height = 720;
    bool fullScreen = false;

    std::list<IRenderable*> renderables;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

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
    void Load(const json::JSON& json); 

private:
    RenderSystem() = default;
    ~RenderSystem() = default;
    RenderSystem(const RenderSystem&) = delete;
    RenderSystem& operator=(const RenderSystem&) = delete;
};
