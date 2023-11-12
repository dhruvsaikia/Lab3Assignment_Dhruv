#pragma once

#include "Component.h"
#include "IRenderable.h"
#include "json.hpp" 

class Sprite : public Component, IRenderable
{
public:
    Sprite();
    ~Sprite();

    void Load(const json::JSON& json) override;

protected:
    void Render() override;
};
