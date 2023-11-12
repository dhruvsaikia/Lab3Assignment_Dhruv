#include "EngineTime.h"

void Time::Update()
{
    auto now = std::chrono::system_clock::now();

    if (frameCount == 0) 
        beginTime = now;

    endTime = now;
    deltaTime = endTime - beginTime;
    beginTime = endTime;
    totalTime += deltaTime;
    frameCount++;
}

void Time::Initialize()
{
    beginTime = std::chrono::system_clock::now();
    endTime = std::chrono::system_clock::now();
    deltaTime = std::chrono::duration<float>(0);
    totalTime = std::chrono::duration<float>(0);
    frameCount = 0;
}

void Time::Destroy()
{
}
