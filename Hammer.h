#pragma once

#include <iostream>
#include <string>
#include <sgg/graphics.h>

#include "GameObject.h"

using namespace std;

class Hammer : public GameObject
{
protected:
	virtual void prepareBrush();
public:
	Hammer();
};
