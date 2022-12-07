#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class GameObject;
class Sprite;
class RectShape;
class Collider;
class CircleShape;

struct Scene {
	static std::vector<GameObject*> _createdObjects;
	static std::vector<uint32_t> _availableId;
	static uint32_t _objectCounter;

	static std::vector<Sprite*> createdSprites;
	static std::vector<RectShape*> createdRects;
	static std::vector<Collider*> createdColliders;
	static std::vector<CircleShape*> createdCircles;
};