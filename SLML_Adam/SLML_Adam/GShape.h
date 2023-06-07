#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once

using namespace std;
using namespace sf;

class GShape :public Drawable
{
protected:
	RectangleShape shape;

	float Speed{ 8.0f };
	Vector2f velocity{ Speed,0.f };

	GShape(float X, float Y, float W, float H, Color C);
	
	virtual bool update(bool col = true) = 0;
	Vector2f getPosition();

	float left();
	float right();
	float top();
	float bottom();
	
	friend bool IsCollision(GShape* gs0, GShape* gs1);
private:
	void draw(RenderTarget& target, RenderStates state) const;
};

