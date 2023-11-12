#include "Object.h"
#include <iostream>

Object::Object() : initialized(false), id(0)
{
    std::cout << "Object is Created" << std::endl;
}

Object::~Object()
{
    std::cout << "Object is Destroyed" << std::endl;
}

void Object::Load(const JSON& json)
{
}
