#include "RectShape.h"

RectShape::~RectShape() {
	Scene::createdRects[_gameObjectId] = nullptr;
	delete Scene::createdRects[_gameObjectId];
}

bool RectShape::setTexture(std::string file) {
	if (!_tex.loadFromFile(file)) {
		std::cerr << "Could not load file: " << file << std::endl;
		return false;
	}
	_rectangleShape.setTexture(&_tex);
	return true;
}

void RectShape::setRGBColor(sf::Vector3<int> color) {
	_rectangleShape.setFillColor(sf::Color(color.x, color.y, color.z));
}

void RectShape::setPosition(sf::Vector2<float> position) {
	Scene::_createdObjects[_gameObjectId]->position = position;
	_rectangleShape.setPosition(position);
}

void RectShape::rectangleShape(sf::Vector2<float> xy) {
	_rectangleShape.setSize(xy);
}

sf::FloatRect RectShape::getBounds() {
	sf::FloatRect rectangleRect = _rectangleShape.getLocalBounds();
	return sf::FloatRect(Scene::_createdObjects[_gameObjectId]->position.x,
						 Scene::_createdObjects[_gameObjectId]->position.y,
						 rectangleRect.width, rectangleRect.height);
}

void RectShape::setMovable() {
	_isMovable = true;
}

void RectShape::Draw(sf::RenderWindow& window) {
	if (_isMovable) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Scene::_createdObjects[_gameObjectId]->position.x >= 0) {
			Scene::_createdObjects[_gameObjectId]->position.x -= 0.2f;
			_rectangleShape.move(-0.2f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Scene::_createdObjects[_gameObjectId]->position.x <= 600) {
			Scene::_createdObjects[_gameObjectId]->position.x += 0.2f;
			_rectangleShape.move(+0.2f, 0.f);
		}
		std::cout << "New position: " << Scene::_createdObjects[_gameObjectId]->position.x << ", " << Scene::_createdObjects[_gameObjectId]->position.y << std::endl;
	}

	window.draw(_rectangleShape);
}
