#include "Physics.h"

Physics::~Physics() {
	Scene::createdPhysics[gameObjectId] = nullptr;
}

void Physics::setSpeed(const sf::Vector2<float>& speed) {
	_speed = speed;
}

void Physics::update() {
	sf::Vector2<float> pos = getPosition();
	pos += _speed;
	setPosition(pos);
}
