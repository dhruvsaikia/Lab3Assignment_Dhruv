#include "Engine.h"
#include "EngineTime.h"
#include "RenderSystem.h"
#include "Entity.h"
#include <thread>

void Engine::Initialize()
{
	RenderSystem::Instance().Initialize();
}

void Engine::Destroy()
{
	Time::Instance().Destroy();
}

void Engine::GameLoop()
{
	while (true)
	{
		Time::Instance().Update();
		if (Time::Instance().TotalTime() > 5.0f)
		{
			break;
		}
	}
}

void Engine::Load()
{
}
