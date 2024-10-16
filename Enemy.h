#pragma once

#include <iostream>
#include <string>
#include <sgg/graphics.h>

#include "GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy(float x = 50, float y = 50, float width = 10, float height = 10); 
	// Constructor declaration with default parameters
};
