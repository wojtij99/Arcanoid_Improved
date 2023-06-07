#pragma once
#include "GShape.h"
#include <SFML/Graphics.hpp>

class Ball :public GShape
{
	CircleShape cShape;

	float Speed{ 6.0f };
	Vector2f velocity{ Speed, Speed };

public:
	Ball();

	void reset();
	bool update(bool col);
private:
	void draw(RenderTarget& target, RenderStates state) const;
};

