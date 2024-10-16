#pragma once

#include <iostream>
#include <string>
#include <sgg/graphics.h>
#include "Monkey.h"
#include "Barrel.h"
#include "Friend.h"
#include "Ladder.h"

#include "GameObject.h"

#include <vector>

using namespace std;

class Mario : public GameObject
{
public:
	string texture_walking_left[3];
	string texture_walking_right[3];
	graphics::Brush br_walking_left[3];
	graphics::Brush br_walking_right[3];
	graphics::Brush br_debug;
	float age = 0;
	bool jumping = false;
	bool ground = true;
	float t_jump = 0;

	int lives = 3;
	int score = 0;

	bool moving_left = false;
	bool moving_right = true;
	bool moving_up = false;
	bool moving_down = false;
	
	float speed = 0.05f;
	float gravity = 0.03f;

	Mario();

	void draw();
	void update(float t, vector<Ladder> & ladders);

	void moveLeft(float t);
	void moveRight(float t);
	void moveUp(float t);
	void moveDown(float t);

	void resetPosition();
	void loseLife();
	void gainScore();
	void checkCollision(Enemy& enemy);
	void checkCollision(Friend& enemy);
	bool checkCollisionUp(float x, float y, Ladder& ladder);
	bool checkCollisionDown(float x, float y, Ladder& ladder);

};

