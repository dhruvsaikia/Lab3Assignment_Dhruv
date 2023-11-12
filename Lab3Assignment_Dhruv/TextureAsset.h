#pragma once

#include "Asset.h"
#include "json.hpp" 

class TextureAsset : public Asset
{
public:
    TextureAsset();
    ~TextureAsset();

    void Load(const json::JSON& json) override;
};
