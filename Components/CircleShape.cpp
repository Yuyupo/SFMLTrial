#include "CircleShape.h"

CircleShape::~CircleShape() {
	Scene::createdCircles[_gameObjectId] = nullptr;
	delete Scene::createdCircles[_gameObjectId];
}

bool CircleShape::setTexture(std::string file) {
	if (!_tex.loadFromFile(file)) {
		std::cerr << "Could not load file: " << file << std::endl;
		return false;
	}
	_circleShape.setTexture(&_tex);
	return true;
}

void CircleShape::setRGBColor(sf::Vector3<int> color) {
	_circleShape.setFillColor(sf::Color(color.x, color.y, color.z));
}

void CircleShape::setPosition(sf::Vector2<float> position) {
	Scene::_createdObjects[_gameObjectId]->position = position;
	_circleShape.setPosition(position);

}

void CircleShape::circleShape(float radius) {
	_circleShape.setRadius(radius);
}

sf::FloatRect CircleShape::getBounds() {
	sf::FloatRect rectangleRect = _circleShape.getLocalBounds();
	return sf::FloatRect(Scene::_createdObjects[_gameObjectId]->position.x,
						 Scene::_createdObjects[_gameObjectId]->position.y,
						rectangleRect.width, rectangleRect.height);
}

float dot(const sf::Vector2f& lv, const sf::Vector2f& rv)
{
	return lv.x * rv.x + lv.y * rv.y;
}

sf::Vector2f normalise(sf::Vector2f source)
{
	float length = std::sqrt(dot(source, source));
	if (length != 0) source /= length;
	return source;
}


sf::Vector2f reflect(const sf::Vector2f& velocity, const sf::Vector2f& normal)
{
	return -2.f * dot(velocity, normal) * normal + velocity;
}

void CircleShape::setMovable() {
	_isMovable = true;
}

void CircleShape::Draw(sf::RenderWindow& window, float dt) {
	window.draw(_circleShape);
	_circleShape.move(m_velocity * 500.f * dt);
}
