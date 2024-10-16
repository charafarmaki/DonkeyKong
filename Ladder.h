#pragma once

#include <iostream>
#include <string>
#include <sgg/graphics.h>
#include "GameObject.h"

using namespace std;
class Ladder : public GameObject
{
private:
	graphics::Brush br_debug;
protected:
	virtual void prepareBrush();
public:	
	Ladder(float x, float y);

	void draw();
};
