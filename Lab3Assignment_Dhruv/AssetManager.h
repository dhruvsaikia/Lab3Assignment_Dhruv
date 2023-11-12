#pragma once

#include <list>
#include "Asset.h"

class AssetManager
{
public:
    static AssetManager& Instance()
    {
        static AssetManager instance;
        return instance;
    }

    void Initialize();
    void Destroy();
    void Update();

    void AddAsset(Asset* _asset);
    void RemoveAsset(Asset* _asset);

private:
    AssetManager() = default;
    ~AssetManager() = default;

    std::list<Asset*> assets;
};
