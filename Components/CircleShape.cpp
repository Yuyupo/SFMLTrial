#include "CircleShape.h"

CircleShape::~CircleShape() {
	Scene::createdCircles[gameObjectId] = nullptr;
}

bool CircleShape::setTexture(const std::string& file) {
	if (!_tex.loadFromFile(file)) {
		std::cerr << "Could not load file: " << file << std::endl;
		return false;
	}
	_circleShape.setTexture(&_tex);
	return true;
}

void CircleShape::setRGBColor(const sf::Vector3<int>& color) {
	_circleShape.setFillColor(sf::Color(color.x, color.y, color.z));
}

void CircleShape::circleShape(float radius) {
	_circleShape.setRadius(radius);
}

sf::FloatRect CircleShape::getBounds() {
	sf::FloatRect rectangleRect = _circleShape.getLocalBounds();
	return sf::FloatRect(getPosition().x, getPosition().y,
						 rectangleRect.width, rectangleRect.height);
}

void CircleShape::Draw(sf::RenderWindow& window) {
	_circleShape.setPosition(getPosition());
	window.draw(_circleShape);
}
