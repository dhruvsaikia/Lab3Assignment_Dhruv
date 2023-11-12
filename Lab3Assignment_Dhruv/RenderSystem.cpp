#include "RenderSystem.h"

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
}

void RenderSystem::Destroy()
{
}

void RenderSystem::Update()
{
    for (auto& renderable : renderables)
    {
        renderable->Render();
    }
}

void RenderSystem::Load()
{
}
