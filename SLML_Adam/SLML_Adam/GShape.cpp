#include "GShape.h"

GShape::GShape(float X, float Y, float W, float H, Color C)
{
	shape.setPosition(X, Y);
	shape.setSize({ W,H });
	shape.setFillColor(C);
	shape.setOrigin(W / 2.f, H / 2.f);
}


void GShape::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

float GShape::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}

float GShape::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}

float GShape::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

float GShape::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

Vector2f GShape::getPosition()
{
	return shape.getPosition();
}