#pragma once

#include <string>
#include "json.hpp" 

#define DECLARE_CLASS(className) static Object* Create() { return new className(); }

class Object
{
private:
    bool initialized = false;
    std::string name = "";
    int id = 0;

protected:
    Object();
    virtual ~Object();

public:
    virtual void Initialize() = 0;
    virtual void Destroy() {};

    virtual void Load(const json::JSON& json);

    bool IsInitialize() const { return initialized; }
    const std::string& GetName() const { return name; }
    int GetId() const { return id; }
};
