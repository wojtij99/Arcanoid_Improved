#include <SFML/Graphics.hpp>
#include <iostream>
#include "GShape.h"
#pragma once

using namespace std;
using namespace sf;

class Paddle : public GShape
{
public:
	Paddle();

	bool update(bool col = true);
};

