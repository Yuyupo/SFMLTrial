#pragma once
#include <SFML/Graphics.hpp>

#include "Components/Sprite.h"
#include "Components/RectShape.h"
#include "Components/Collider.h"
#include "Components/CircleShape.h"

#include <memory>
#include <array>
#include <iostream>

class GameObject
{
public:
	GameObject();
	// TODO: gameobject masolas befejez
	GameObject(const GameObject& other);
	GameObject(GameObject&& other);

	GameObject& operator=(const GameObject& other) noexcept;
	GameObject& operator=(GameObject&& other) noexcept;

	~GameObject();

	void addSpriteComponent();
	Sprite* getSpriteComponent() const;

	void addRectComponent();
	RectShape* getRectComponent() const;

	void addColliderComponent();
	Collider* getColliderComponent() const;

	void addCircleComponent();
	CircleShape* getCircleComponent() const;

	uint32_t uniqueId{};
	sf::Vector2<float> position{ 0, 0 };
	std::array<Component*, ComponentEnum::SIZE> components;
private:
	void allocateId();
};

