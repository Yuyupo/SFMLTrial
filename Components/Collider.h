#pragma once
#include "Component.h"

class Collider : public Component
{
public:
	Collider(uint32_t id) : Component( id ) { Scene::createdColliders[id] = this; };

	virtual ~Collider();

	// Local bounds
	void createColliderWithSize(const sf::Vector2<float>&);
	void makeDestructible();
	bool isDestructible() const { return _isDestructible; };
	void interactsWithVector(const std::vector<GameObject*>&);
	std::vector<Collider*> isColliding(); // std::vector<Collider*>& collided
	void DrawDebug(sf::RenderWindow&);


private:
	sf::FloatRect getColliderBounds();

	bool _isDestructible{ false };
	std::vector<uint32_t> _interactsWith;
	sf::Vector2<float> _colliderSize{};
};

