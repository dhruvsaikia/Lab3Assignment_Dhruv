#pragma once

#ifndef _TIME_H_
#define _TIME_H_

#include <chrono>

class Time
{
public:
    static Time& Instance()
    {
        static Time instance; 
        return instance;
    }

    void Destroy();
    void Update();

    float DeltaTime() const { return deltaTime.count(); }
    float TotalTime() const { return totalTime.count(); }
    unsigned int FrameCount() const { return frameCount; }

private:
    Time();  
    ~Time(); 
    Time(const Time&) = delete; 
    Time& operator=(const Time&) = delete; 

    void Initialize();

    unsigned int frameCount = 0;
    std::chrono::duration<float> deltaTime = std::chrono::duration<float>(0.0f);
    std::chrono::duration<float> totalTime = std::chrono::duration<float>(0.0f);
    std::chrono::time_point<std::chrono::system_clock> beginTime;
    std::chrono::time_point<std::chrono::system_clock> endTime;
};

#endif