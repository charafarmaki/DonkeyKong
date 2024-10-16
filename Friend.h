#pragma once

#include <iostream>
#include <string>
#include <sgg/graphics.h>

#include "GameObject.h"

class Friend : public GameObject
{
public:
	Friend(float x = 50, float y = 50, float width = 10, float height = 10);
};
