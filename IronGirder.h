#pragma once

#include <iostream>
#include <string>
#include <sgg/graphics.h>

#include "GameObject.h"

using namespace std;

class IronGirder : public GameObject
{
protected:
	virtual void prepareBrush();
public:
	IronGirder(float x, float y);

	void draw();
	void update();
};
