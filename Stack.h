#pragma once

#include <iostream>
#include <string>
#include <sgg/graphics.h>

#include "GameObject.h"

using namespace std;

class Stack : public GameObject
{
protected:
	virtual void prepareBrush();
public:
	Stack(float x = 11.0f, float y = 20.5f);
};
