#pragma once
#include <SFML/Graphics.hpp>

#include <memory>
#include <array>
#include <iostream>

class Sprite;
class RectShape;
class Collider;
class CircleShape;
class Physics;
class Component;

class GameObject
{
public:
	GameObject();
	// TODO: gameobject masolas befejez

	GameObject(const GameObject& other) = delete;
	GameObject(GameObject&& other) = delete;

	GameObject& operator=(const GameObject& other) = delete;
	GameObject& operator=(GameObject&& other) = delete;

	~GameObject();

	void addSpriteComponent();
	Sprite* getSpriteComponent() const;

	void addRectComponent();
	RectShape* getRectComponent() const;

	void addColliderComponent();
	Collider* getColliderComponent() const;

	void addCircleComponent();
	CircleShape* getCircleComponent() const;

	void addPhysicsComponent();
	Physics* getPhysicsComponent() const;

	void setPosition(const sf::Vector2<float>&);

	uint32_t uniqueId{};
	sf::Vector2<float> position{ 0, 0 };
private:
	void allocateId();
};

