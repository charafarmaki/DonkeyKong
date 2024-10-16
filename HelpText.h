#pragma once

#include <iostream>
#include <string>
#include <sgg/graphics.h>

#include "GameObject.h"

using namespace std;

class HelpText : public GameObject
{

protected:
	virtual void prepareBrush();
public:
	float size;
	float age = 0;

	bool display = true;

	HelpText(float x = 74, float y = 9, float size = 2);

	void draw();
	void update(float t);
};


