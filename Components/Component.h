#pragma once
#include <SFML/Graphics.hpp>
#include "../Scene.h"
#include "../GameObject.h"

class Component
{
public:
	uint32_t gameObjectId;
	virtual ~Component() {};

	void setPosition(sf::Vector2<float>& pos) {
		Scene::_createdObjects[gameObjectId]->position = pos;
	};

	sf::Vector2<float>& getPosition() const {
		return Scene::_createdObjects[gameObjectId]->position;
	};

	GameObject* getGameObject() const {
		return Scene::_createdObjects[gameObjectId];
	}

protected:
	Component(uint32_t id) : gameObjectId(id) {};
};
