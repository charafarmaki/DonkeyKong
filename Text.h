#pragma once

#include <iostream>
#include <string>
#include <sgg/graphics.h>

#include "GameObject.h"

using namespace std;

class Text : public GameObject {
protected:
	virtual void prepareBrush();
public:
	string text;
	float size;

	virtual void draw() const;

	Text();
};
