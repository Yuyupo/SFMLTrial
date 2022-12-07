#include "GameObject.h"

void GameObject::addSpriteComponent() {
	components[ComponentEnum::SPRITE] = new Sprite(uniqueId);
}

Sprite* GameObject::getSpriteComponent() const {
	return (Sprite*) components[ComponentEnum::SPRITE];
}

void GameObject::addRectComponent() {
	components[ComponentEnum::RECTSHAPE] = new RectShape(uniqueId);
}

RectShape* GameObject::getRectComponent() const {
	return (RectShape*) components[ComponentEnum::RECTSHAPE];
}

void GameObject::addColliderComponent() {
	components[ComponentEnum::COLLIDER] = new Collider(uniqueId);
}

Collider* GameObject::getColliderComponent() const {
	return (Collider*) components[ComponentEnum::COLLIDER];
}
void GameObject::addCircleComponent() {
	components[ComponentEnum::CIRCLESHAPE] = new CircleShape(uniqueId);
}

CircleShape* GameObject::getCircleComponent() const {
	return (CircleShape*) components[ComponentEnum::CIRCLESHAPE];
}

GameObject::GameObject() {
	allocateId();

	components.fill(nullptr);

	Scene::_createdObjects.resize(Scene::_objectCounter);
	Scene::_createdObjects[uniqueId] = this;

	Scene::createdSprites.resize(Scene::_objectCounter);
	Scene::createdRects.resize(Scene::_objectCounter);
	Scene::createdColliders.resize(Scene::_objectCounter);
	Scene::createdCircles.resize(Scene::_objectCounter);
}

// Duplicate Game Object
GameObject::GameObject(const GameObject& other) {
	allocateId();

	position = other.position;

	for (uint32_t index = 0; index < ComponentEnum::SIZE; index++) {
		if (other.components[index] != nullptr) {
			// copy construct egysevel componentenkent
			components[index] = new Component(*other.components[index]);
		}
	}

	Scene::_createdObjects.resize(Scene::_objectCounter);
	Scene::_createdObjects[uniqueId] = this;
}

GameObject::GameObject(GameObject&& other) {
	uniqueId = other.uniqueId;
	position = std::move(other.position);
	/*
	for (uint32_t index = 0; index < ComponentEnum::SIZE; index++) {
		components[index] = other.components[index];
	}
	*/
	Scene::_createdObjects[uniqueId] = this;
}

GameObject& GameObject::operator=(const GameObject& other) noexcept {
	if (&other == this) {
		return *this;
	}

	allocateId();

	position = other.position;

	Scene::_createdObjects.resize(Scene::_objectCounter);
	Scene::_createdObjects[uniqueId] = this;
	return *this;
}

GameObject& GameObject::operator=(GameObject&& other) noexcept {
	if (&other == this) {
		return *this;
	}

	uniqueId = other.uniqueId;
	position = std::move(other.position);
	/*
	for (uint32_t index = 0; index < ComponentEnum::SIZE; index++) {
		components[index] = other.components[index];
	}
	*/

	Scene::_createdObjects[uniqueId] = this;
	return *this;
}

GameObject::~GameObject() {
	for (auto* component : components) {
		if (component != NULL) {
			delete component;
		}
	}

	Scene::_availableId.push_back(uniqueId);
	Scene::_createdObjects[uniqueId] = nullptr;
}

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