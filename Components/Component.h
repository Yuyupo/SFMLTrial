#pragma once
#include <SFML/Graphics.hpp>
#include "..\Scene.h"

// Only one of each component is available
enum ComponentEnum
{
	SPRITE,
	RECTSHAPE,
	COLLIDER,
	CIRCLESHAPE,
	SIZE
};

class Component
{
public:
	uint32_t _gameObjectID;
	virtual ~Component() {};
protected:
	Component(uint32_t id) : _gameObjectID(id) {};
};
