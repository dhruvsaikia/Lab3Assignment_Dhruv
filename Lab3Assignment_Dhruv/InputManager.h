#pragma once

class InputManager
{
public:
    static InputManager& Instance()
    {
        static InputManager instance;
        return instance;
    }

    void Initialize();
    void Destroy();
    void Update();

private:
    InputManager() = default;
    ~InputManager() = default;
    InputManager(const InputManager&) = delete;
    InputManager& operator=(const InputManager&) = delete;
};
