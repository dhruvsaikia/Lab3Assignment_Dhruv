#pragma once

#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <list>

class Engine
{
public:

	static Engine& Instance()
	{
		static Engine instance;
		return instance;
	}

	void Initialize();
	void Destroy();
	void GameLoop();
	void Load(); 

private:
	Engine() = default;
	~Engine() = default;
	Engine(Engine const&) = delete;
	Engine& operator=(Engine const&) = delete;
};

#endif
