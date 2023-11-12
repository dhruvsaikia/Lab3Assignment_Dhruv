#pragma once

#include <string>

class Asset
{
public:
    Asset();
    virtual ~Asset();
    virtual bool Load(const std::string& filePath) = 0;
};