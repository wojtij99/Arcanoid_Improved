#include "Paddle.h"

Paddle::Paddle():GShape(700, 700, 75,20, Color(133,133,133))
{
	;
}

bool Paddle::update(bool col)
{
	if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && this->left() > 0)
	{
		velocity.x = -Speed;
	}
	else if((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) && this->right() < 1260)
	{
		velocity.x = Speed;
	}
	else
	{
		velocity.x = 0;
	}

	this->shape.move(velocity);
	return true;
}
