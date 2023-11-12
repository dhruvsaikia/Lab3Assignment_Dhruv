#pragma once

#include <string>
#include "json.hpp" 

class Asset
{
public:
    Asset();
    virtual ~Asset();
    virtual void Load(const json::JSON& jsonData) = 0;
};
