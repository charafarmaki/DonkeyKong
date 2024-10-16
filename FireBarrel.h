#pragma once

#include <iostream>
#include <string>
#include <sgg/graphics.h>

#include "GameObject.h"

using namespace std;

class FireBarrel : public GameObject
{
protected:
	virtual void prepareBrush();
public:
	FireBarrel();
};
