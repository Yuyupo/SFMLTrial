#include "RectShape.h"

RectShape::~RectShape() {
	Scene::createdRects[gameObjectId] = nullptr;
}

bool RectShape::setTexture(const std::string& file) {
	if (!_tex.loadFromFile(file)) {
		std::cerr << "Could not load file: " << file << std::endl;
		return false;
	}
	_rectangleShape.setTexture(&_tex);
	return true;
}

void RectShape::setRGBColor(const sf::Vector3<int>& color) {
	_rectangleShape.setFillColor(sf::Color(color.x, color.y, color.z));
}

void RectShape::rectangleShape(const sf::Vector2<float>& xy) {
	_rectangleShape.setSize(xy);
}

sf::FloatRect RectShape::getBounds() {
	sf::FloatRect rectangleRect = _rectangleShape.getLocalBounds();
	sf::Vector2<float> position = getPosition();
	return sf::FloatRect(position.x, position.y,
						 rectangleRect.width, rectangleRect.height);
}

void RectShape::Draw(sf::RenderWindow& window) {
	_rectangleShape.setPosition(getPosition());
	window.draw(_rectangleShape);
}
