#pragma once

#include <iostream> 
#include <string> 
#include <sgg/graphics.h> 

#include "Enemy.h" // Include Enemy header file

using namespace std;


enum BarrelPath {
	FirstLadderDrop,
	RandomLadderDrop,
	PlatformDrop,
	VerticalDrop
};

enum Direction {
	Left,
	Right,
	Down
};

class Barrel : public Enemy // Define Barrel class inheriting from Enemy
{
protected:
	virtual void prepareBrush();

public:	
	string texture[2]; // Declare texture array for two textures
	graphics::Brush br[2];
	Direction direction = Direction::Right; // Initialize direction to Right
	float speed = 0.01f; // Initialize speed
	BarrelPath path;

	float next_platform_y = 38.5f;

	Barrel(BarrelPath path);

	void draw();
	void update(float t);


private:
	void path1(float t);
	void path2(float t);
	void path3(float t);
	void path4(float t);

};
