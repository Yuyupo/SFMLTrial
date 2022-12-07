#pragma once
#include "Component.h"
#include "..\GameObject.h"

class RectShape : public Component
{
public:
	RectShape(uint32_t id) : Component({ id }), _gameObjectId(id) { Scene::createdRects[id] = this; };
	// _pos(Scene::_createdObjects[id]->position)
	virtual ~RectShape();

	bool setTexture(std::string file);
	void setRGBColor(sf::Vector3<int> color);
	void setPosition(sf::Vector2<float> position);
	void rectangleShape(sf::Vector2<float> xy);
	sf::FloatRect getBounds();
	void setMovable();

	void Draw(sf::RenderWindow& window);

private:
	uint32_t _gameObjectId{0};

	bool _isMovable{ false };
	sf::RectangleShape _rectangleShape{};
	sf::Vector3<int> _color{ 0, 0, 0 };
	sf::Texture _tex{};
};

