#include <iostream>
#include "Engine.h"
#include "RenderSystem.h"
#include "json.hpp"
#include <fstream>
#include <sstream>

int main(int argc, char* argv[])
{
    std::ifstream ifs("RenderSystem.json");
    if (!ifs.is_open()) {
        std::cerr << "Could not open RenderSystem.json for reading." << std::endl;
        return -1;
    }

    std::stringstream buffer;
    buffer << ifs.rdbuf();
    ifs.close();

    json::JSON jsonSettings;
    try {
        jsonSettings = json::JSON::Load(buffer.str());
    }
    catch (const std::exception& e) {
        std::cerr << "Failed to parse JSON settings: " << e.what() << std::endl;
        return -1;
    }

    RenderSystem::Instance().Load(jsonSettings);

    Engine::Instance().Initialize();
    Engine::Instance().GameLoop();
    Engine::Instance().Destroy();

    return 0;
}
