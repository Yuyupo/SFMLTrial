#include "GameObject.h"

#include "Components/Sprite.h"
#include "Components/RectShape.h"
#include "Components/Collider.h"
#include "Components/CircleShape.h"
#include "Components/Physics.h"

void GameObject::addSpriteComponent() {
	if (Scene::createdSprites[uniqueId] == nullptr) {
		new Sprite(uniqueId);
	}
}

Sprite* GameObject::getSpriteComponent() const {
	return Scene::createdSprites[uniqueId];
}

void GameObject::addRectComponent() {
	if (Scene::createdRects[uniqueId] == nullptr) {
		new RectShape(uniqueId);
	}
}

RectShape* GameObject::getRectComponent() const {
	return Scene::createdRects[uniqueId];
}

void GameObject::addColliderComponent() {
	if (Scene::createdColliders[uniqueId] == nullptr) {
		new Collider(uniqueId);
	}
}

Collider* GameObject::getColliderComponent() const {
	return Scene::createdColliders[uniqueId];
}
void GameObject::addCircleComponent() {
	if (Scene::createdCircles[uniqueId] == nullptr) {
		new CircleShape(uniqueId);
	}
}

CircleShape* GameObject::getCircleComponent() const {
	return Scene::createdCircles[uniqueId];
}

void GameObject::addPhysicsComponent() {
	if (Scene::createdPhysics[uniqueId] == nullptr) {
		new Physics(uniqueId);
	}
}

Physics* GameObject::getPhysicsComponent() const {
	return Scene::createdPhysics[uniqueId];
}

void GameObject::setPosition(const sf::Vector2<float>& pos) {
	position = pos;
}

GameObject::GameObject() {
	allocateId();

	Scene::_createdObjects.resize(Scene::_objectCounter);
	Scene::_createdObjects[uniqueId] = this;

	Scene::createdSprites.resize(Scene::_objectCounter);
	Scene::createdSprites[uniqueId] = nullptr;

	Scene::createdRects.resize(Scene::_objectCounter);
	Scene::createdRects[uniqueId] = nullptr;

	Scene::createdColliders.resize(Scene::_objectCounter);
	Scene::createdColliders[uniqueId] = nullptr;

	Scene::createdCircles.resize(Scene::_objectCounter);
	Scene::createdCircles[uniqueId] = nullptr;

	Scene::createdPhysics.resize(Scene::_objectCounter);
	Scene::createdPhysics[uniqueId] = nullptr;
}

GameObject::~GameObject() {
	delete getSpriteComponent();
	delete getRectComponent();
	delete getColliderComponent();
	delete getCircleComponent();
	delete getPhysicsComponent();

	Scene::_availableId.push_back(uniqueId);
	Scene::_createdObjects[uniqueId] = nullptr;
}

// Check if there is available ID from the deleted objects
void GameObject::allocateId() {
	if (!Scene::_availableId.empty()) {
		uniqueId = Scene::_availableId.back();
		Scene::_availableId.pop_back();
	}
	else {
		uniqueId = Scene::_objectCounter;
		Scene::_objectCounter++;
	}
}
