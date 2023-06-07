#pragma once
#include "GShape.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Block : public GShape
{
public:
	Block(float X, float Y);

	bool update(bool col = true) { return true; }
};

