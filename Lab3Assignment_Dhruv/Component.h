#pragma once

#include "Object.h"
#include <string>

class Component : public Object
{
public:
	Component();
	virtual ~Component() override;

	void Initialize() override;
	virtual void Update();
	virtual void Destroy() override;
	virtual void Load(const JSON& json) = 0;

	friend class Entity;
};
