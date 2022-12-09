#include "Collider.h"
#include <iostream>
#include <memory>

Collider::~Collider() {
	Scene::createdColliders[gameObjectId] = nullptr;
}

void Collider::createColliderWithSize(const sf::Vector2<float>& size) {
	_colliderSize = size;
}

void Collider::makeDestructible() {
	_isDestructible = true;
}

void Collider::interactsWithVector(const std::vector<GameObject*>& interactions) {
	_interactsWith.resize(0);

	for (auto* object : interactions) {
		_interactsWith.push_back(object->uniqueId);
	}
}

std::vector<Collider*> Collider::isColliding() {
	std::vector<Collider*> colls;
	// mivel mindig updatel a gameobject position
	// ezert annak a positionje alapjan csinalunk uj collidert, majd csekk
	// igy nem kell a collidert mozgatni
	sf::FloatRect thisCollider = getColliderBounds();
	for (int index = 0; index < _interactsWith.size(); index++) {
		Collider* collider = Scene::createdColliders[_interactsWith[index]];
		if (collider != nullptr && collider->gameObjectId != gameObjectId) {
			if (thisCollider.intersects(collider->getColliderBounds())) {
				colls.push_back(collider);
			}
		}
	}
	return colls;
}

void Collider::DrawDebug(sf::RenderWindow& window) {
	sf::RectangleShape debugRect({ _colliderSize.x + 3, _colliderSize.y + 3 });
	debugRect.setOutlineColor(sf::Color(255, 0, 255));
	debugRect.setFillColor(sf::Color::Transparent);
	debugRect.setOutlineThickness(3.f);

	debugRect.setPosition({ getPosition().x - 1.5f, getPosition().y - 1.5f });
	window.draw(debugRect);
}

sf::FloatRect Collider::getColliderBounds() {
	return sf::FloatRect(getPosition().x, getPosition().y, _colliderSize.x, _colliderSize.y);
}
