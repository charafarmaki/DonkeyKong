#pragma once

#include <iostream>
#include <string>
#include <sgg/graphics.h>

#include "Friend.h"

using namespace std;

class Pauline : public Friend
{
protected:
	virtual void prepareBrush();
public:	
	string texture[2];
	graphics::Brush br[2];
	bool going_right = true;
	bool going_left = false;
	float speed = 0.01f;

	Pauline();

	void draw();
	void update(float t);

};
