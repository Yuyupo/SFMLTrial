#pragma once
#include "Component.h"
#include "..\GameObject.h"

class Collider : public Component
{
public:
	Collider(uint32_t id) : Component({ id }), _gameObjectId(id) { Scene::createdColliders[id] = this; };

	// Local bounds
	void createColliderWithSize(sf::FloatRect bounds);
	void makeDestructible();
	void isColliding(); // std::vector<Collider*>& collided
	void updatePosition();
	void DrawDebug(sf::RenderWindow& window);

	virtual ~Collider();

	bool _isDestructible{ false };
private:
	uint32_t _gameObjectId{ 0 };

	sf::FloatRect _collider{};
	sf::RectangleShape _debugRect{};
};

