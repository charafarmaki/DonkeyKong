#pragma once

#include <iostream>
#include <string>
#include <sgg/graphics.h>
#include <string>

using namespace std;

class GameObject {
protected:
	virtual void prepareBrush();
public:
	float x, y;          //Coordinates of GameObject
	float width, height; //Dimensions of GameObject
	string texture;      //Texture path for GameObject
	graphics::Brush br;  // Brush for drawing GameObject

	//Constructor for GameObject class
	GameObject(float x = 50, float y = 50, float width = 10, float height = 10);

	virtual void draw() const;
	virtual void update(float t);	
};

