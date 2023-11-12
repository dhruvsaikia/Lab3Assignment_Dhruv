#include "RenderSystem.h"
#include <iostream>

void RenderSystem::AddRenderable(IRenderable* renderable)
{
    renderables.push_back(renderable);
}

void RenderSystem::RemoveRenderable(IRenderable* renderable)
{
    renderables.remove(renderable);
}

void RenderSystem::Initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return;  
    }

    Uint32 windowFlags = fullScreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;
    window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, windowFlags);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return;  
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        window = nullptr;
        return;  
    }
}

void RenderSystem::Destroy()
{
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    SDL_Quit();
}

void RenderSystem::Update()
{
    SDL_RenderClear(renderer);

    for (auto& renderable : renderables) {
        renderable->Render();
    }

    SDL_RenderPresent(renderer);
}

void RenderSystem::Load(const json::JSON& json) // i had added some checks and outputs to make sure i was getting the json load right
{
    auto& modifiableJson = const_cast<json::JSON&>(json);

    if (modifiableJson.hasKey("name")) {
        name = modifiableJson["name"].ToString();
        std::cout << "RenderSystem Name: " << name << std::endl;  
    }
    if (modifiableJson.hasKey("width")) {
        width = modifiableJson["width"].ToInt();
        std::cout << "RenderSystem Width: " << width << std::endl;  
    }
    if (modifiableJson.hasKey("height")) {
        height = modifiableJson["height"].ToInt();
        std::cout << "RenderSystem Height: " << height << std::endl; 
    }
    if (modifiableJson.hasKey("fullscreen")) {
        fullScreen = modifiableJson["fullscreen"].ToBool();
        std::cout << "RenderSystem Fullscreen: " << (fullScreen ? "true" : "false") << std::endl; 
    }
}
