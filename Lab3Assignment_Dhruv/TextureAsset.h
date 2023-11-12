#pragma once

#include "Asset.h"


class TextureAsset : public Asset
{
public:
    TextureAsset();
    ~TextureAsset();

    void Load(const JSON& json) override; 
};
