#include "Collider.h"
#include <iostream>
#include <memory>

void Collider::createColliderWithSize(sf::FloatRect bounds) {
	_collider = bounds;

	_debugRect.setSize({ _collider.width + 3, _collider.height + 3 });
	_debugRect.setOutlineColor(sf::Color(255, 0, 255));
	_debugRect.setFillColor(sf::Color::Transparent);
	_debugRect.setOutlineThickness(3.f);
	_debugRect.setPosition({ _collider.left, _collider.top });
}

//GameObject that can destroy
void Collider::makeDestructible() {
	_isDestructible = true;
}

// Megadni neki konstruktorba hogy ki olheti meg? wow thats dark
void Collider::isColliding() {
	/*
	if (_collider.intersects(Scene::createdColliders[_enemyId]->_collider)) {
		std::cout << "Collision detected between: " << _gameObjectID << "," << Scene::createdColliders[_enemyId]->_gameObjectID << std::endl;
		return true;
	}
	*/
	for (int index = 0; index < Scene::_objectCounter; index++) {
		if (Scene::createdColliders[index] != nullptr && Scene::createdColliders[index]->_gameObjectId != _gameObjectId) {
			if (_collider.intersects(Scene::createdColliders[index]->_collider)) {
				std::cout << "Collision detected between: " << _gameObjectID << "," << Scene::createdColliders[index]->_gameObjectID << std::endl;

				delete Scene::_createdObjects[index];
			}
		}
	}
}

void Collider::updatePosition() {
	float offsetX = Scene::_createdObjects[_gameObjectId]->position.x - _collider.left;
	_collider.left = Scene::_createdObjects[_gameObjectId]->position.x;
	_collider.top = Scene::_createdObjects[_gameObjectId]->position.y;
	_debugRect.move({ offsetX, 0.f });
}

void Collider::DrawDebug(sf::RenderWindow& window) {

	// TODO: need another way to check for collision
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		updatePosition();
		isColliding();
	}
	window.draw(_debugRect);
}

Collider::~Collider() {
	Scene::createdColliders[_gameObjectId] = nullptr;
	delete Scene::createdColliders[_gameObjectId];
}
