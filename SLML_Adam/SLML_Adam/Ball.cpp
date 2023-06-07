#include "Ball.h"

Ball::Ball() :GShape(630,670,16,16,Color(255,0,0))
{
	cShape.setPosition(630, 670);
	cShape.setRadius(10);
	cShape.setFillColor(Color(255, 255, 255));
	cShape.setOrigin(10, 10);
}

void Ball::reset()
{
	cShape.setPosition(630, 670);
}

bool Ball::update(bool col)
{
	if (this->left() < 0)
	{
		velocity.x = Speed;
	}
	else if (this->right() > 1260)
	{
		velocity.x = -Speed;
	}

	if (this->top() < 0)
	{
		velocity.y = Speed;
	}
	else if (this->bottom() > 760)
	{
		velocity.y = -Speed;
		return false;
	}

	if (col)
	{
		velocity.y = -velocity.y;
	}

	shape.move(this->velocity);
	cShape.move(this->velocity);

	return true;
}

void Ball::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->cShape, state);
	//target.draw(this->shape, state);
}
