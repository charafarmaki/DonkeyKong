#pragma once

#include <iostream>
#include <string>
#include <sgg/graphics.h>

#include "GameObject.h"

using namespace std;

class ScoreText : public GameObject 
{
public:
	float size;    
	string label;
	int * score;

	ScoreText(float x, float y, float size, string label, int* score);

	void draw();
};
