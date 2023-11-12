#pragma once

#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Component.h"
#include "IRenderable.h"

class Sprite : public Component, IRenderable
{
public:
    Sprite();
    ~Sprite();

    void Load(const JSON& json) override; 

protected:
    void Render() override;
};

#endif
