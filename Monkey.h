#pragma once

#include <iostream>
#include <string>
#include <sgg/graphics.h>

#include "Enemy.h"

using namespace std;

//Monkey is an Enemy
class Monkey : public Enemy
{
protected:
	virtual void prepareBrush();

public:
	string texture[3];
	graphics::Brush br[3];
	float age = 0;

	Monkey(float x, float y);

	virtual void draw() const;
	virtual void update(float t);

};
