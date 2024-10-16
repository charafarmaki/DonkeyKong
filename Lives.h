#pragma once

#include <iostream>
#include <string>
#include <sgg/graphics.h>
#include "GameObject.h"

using namespace std;

class Lives : public GameObject
{
protected:
	virtual void prepareBrush();
public:
	Lives(float x, float y);	
};
