#include <sgg/graphics.h>
#include <stdlib.h>
#include "Mario.h"
#include "Monkey.h"
#include "Pauline.h"
#include "constants.h"
//#include "main.cpp"

using namespace std;

Mario::Mario() 
{
	resetPosition();
	width = 3; 
	height = 6;   


	texture_walking_left[0] = "assets/mario2.png"; //Different assets for Mario
	texture_walking_left[1] = "assets/mario4.png";
	texture_walking_left[2] = "assets/mario4.png";

	texture_walking_right[0] = "assets/mario1.png";
	texture_walking_right[1] = "assets/mario3.png";
	texture_walking_right[2] = "assets/mario3.png";

	for (int i = 0; i < 3; i++) {
		br_walking_left[i].fill_color[0] = 1.0f; //Walking left
		br_walking_left[i].fill_color[1] = 1.0f;
		br_walking_left[i].fill_color[2] = 1.0f;
		br_walking_left[i].outline_opacity = 0.0f;
		br_walking_left[i].texture = texture_walking_left[i];
	}

	for (int i = 0; i < 3; i++) {
		br_walking_right[i].fill_color[0] = 1.0f; //Walking right
		br_walking_right[i].fill_color[1] = 1.0f;
		br_walking_right[i].fill_color[2] = 1.0f;
		br_walking_right[i].outline_opacity = 0.0f;
		br_walking_right[i].texture = texture_walking_right[i];
	}	

	br_debug.fill_color[0] = 1.0f;
	br_debug.fill_color[1] = 1.0f;
	br_debug.fill_color[2] = 1.0f;
	br_debug.outline_opacity = 1.0f;
	br_debug.fill_opacity = 0.0f;
}

void Mario::draw()
{
	if (moving_left) {
		int state = ((int)age / 10) % 3;
		graphics::drawRect(x, y, width, height, br_walking_left[state]);		
	} else if (moving_up) {
		int state = ((int)age / 10) % 3;
		graphics::drawRect(x, y, width, height, br_walking_left[state]);
	} else if (moving_down) {
		int state = ((int)age / 10) % 3;
		graphics::drawRect(x, y, width, height, br_walking_left[state]);
	}
	else {
		int state = ((int)age / 10) % 3;
		graphics::drawRect(x, y, width, height, br_walking_right[state]);
	}

	if (BORDER_MARIO) {
		graphics::drawRect(x, y, width, height, br_debug);
	}
}

//Update Mario's movement and handle collisions
void Mario::update(float t, vector<Ladder>& ladders)
{
	bool climbing = false; //Indicate if Mario is climbing

	
	//Left if key A is pressed
	if (graphics::getKeyState(graphics::SCANCODE_A)) {
		moveLeft(t);
	}
	//Right if key D is pressed
	if (graphics::getKeyState(graphics::SCANCODE_D)) {
		moveRight(t);
	}
	//Up if key W is pressed
	if (graphics::getKeyState(graphics::SCANCODE_W)) {
		//Check for collision with ladders
		for (Ladder& ladder : ladders) {
			if (checkCollisionUp(x, y, ladder)) {
				moveUp(t);
				jumping = false;
				break;
			}
		}		
	}
	//Down if key S is pressed
	if (graphics::getKeyState(graphics::SCANCODE_S)) {
		//Check for collision with ladders
		for (Ladder& ladder : ladders) {
			if (checkCollisionDown(x, y + speed*t, ladder)) {
				moveDown(t);
				jumping = false;
				break;
			}
		}
	}

	//Check if Mario is climbing
	for (Ladder& ladder : ladders) {
		if (checkCollisionUp(x, y, ladder) && !jumping) {			
			climbing = true;
		}
	}

	//Jumping
	if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
		//If Mario is not jumping and is on the ground
		if (!jumping && ground) {
			jumping = true;
			climbing = false;
			ground = false;
			t_jump = graphics::getGlobalTime(); //Record jump start time

			//Play jump sound effect
			graphics::playSound("assets/sounds/jump.wav", 3);
		}
	}

	//Physics for jumping
	if (jumping) {
		y = y - 2 * gravity * t; //Vertical

		//Jump duration passed limit
		if (graphics::getGlobalTime() - t_jump > 200) {
			jumping = false;
			ground = false;
		}
	}

	if (!climbing) {
		float ymin, ymax;

		//
		// Gravity
		//
		for (int i = 0; i < 5; i++) {
			ymin = 76.0f - 13.0f *i;
			ymax = 89 - 13.0f*i;
			if (y > ymin && y < ymax) { //Mario is within range
				y = y + gravity * t;    //Gravity

				if (y > ymax) {
					y = ymax;
					jumping = false;    //Returns back to ground
					ground = true;
				}
			}
		}

		//Additional conditions for gravity
		int i = 4;
		ymin = 76.0f - 13 * i - 14;
		ymax = 89 - 13 * i - 14 + 0.5f;
		if (y > ymin && y < ymax) {
			y = y + gravity * t;

			if (y > ymax) {
				y = ymax;
				jumping = false; // returns back to ground
				ground = true;
			}
		}

		//Ground collision for horizontal positions
		if (y <= ymin) {
			//Mario is within left or right boundary
			if (x > 77 || x < 47) {
				y = y + gravity * t; //Gravity

				//Check if Mario has reached the ground
				if (y > ymax) {
					y = ymax;
					jumping = false; //Returns back to ground
					ground = true;
				}
			}
		}
	}

	//Debugging
	cout << x << "," << y << " " << " climbing: " << ((climbing) ? "true" : "false") << ", jumping:" << ((jumping) ? "true" : "false") << "ground:" << ((ground) ? "true" : "false") << endl;
}

//Move Mario
void Mario::moveLeft(float t) {
	if (x > 10) {
		x = x - speed*t;
		age += t; //Update Mario's age
		moving_left = true;
		moving_right = false;
		moving_up = false;
		moving_down = false;
	}
}

void Mario::moveRight(float t) {
	if (x < 90) {
		x = x + speed*t;
		age += t;

		moving_left = false;
		moving_right = true;
		moving_up = false;
		moving_down = false;
	}
}

void Mario::moveUp(float t) {
	if (y > 10) {
		y = y - speed * t;
		age += t;
		moving_left = false;
		moving_right = false;
		moving_up = true;
		moving_down = false;
	}

}

void Mario::moveDown(float t) {
	if (y < 90) {
		y = y + speed * t;
		age += t;
		moving_left = false;
		moving_right = false;
		moving_up = false;
		moving_down = true;
	}
}

//Reset Mario's position
void Mario::resetPosition()
{
	x = 15.0f;
	y = 89;
	jumping = false;
	ground = true;
}

//Mario loses a life and he starts again
void Mario::loseLife() {
	lives--;
	resetPosition();

	if (MUSIC_EFFECTS) {
		//If Mario has lives left, play a falling sound
		if (lives > 0) {
			graphics::playSound("assets/sounds/falling_game_over.wav", 3);
		}
		else {
			graphics::playSound("assets/sounds/falling_game_over.wav", 3);
		}
	}
}

//Collision with enemies
void Mario::checkCollision(Enemy& enemy) {
	//Distance between Mario and enemy
	float distance_x = abs(this->x - enemy.x);
	float distance_y = abs(this->y - enemy.y);

	if (distance_x < this->width / 2 + enemy.width / 2 &&
		distance_y < this->height/ 2 + enemy.height / 2)
	{
		loseLife(); //Mario loses a life upon collision
	}	
}

//Collision with friends
void Mario::checkCollision(Friend& afriend) {
	float distance_x = abs(this->x - afriend.x);
	float distance_y = abs(this->y - afriend.y);

	if (distance_x < this->width / 2 + afriend.width / 2 &&
		distance_y < this->height / 2 + afriend.height / 2)
	{
		gainScore(); //Mario gains score when colliding with Pauline
	}
}

//Collision with ladder when moving up
bool Mario::checkCollisionUp(float x, float y, Ladder& ladder)
{
	//Distance between Mario and ladder
	float distance_x = abs(x - ladder.x);
	float distance_y = abs(y - ladder.y);

	if (distance_x < ((this->width + ladder.width) / 3) && distance_y < ((this->height + ladder.height) / 2))
	{
		return true;
	}
	else {
		return false;
	}
}

//Collision with ladder when moving down
bool Mario::checkCollisionDown(float x, float y, Ladder& ladder)
{
	//Distance between Mario and ladder
	float distance_x = abs(x - ladder.x);

	//Mario's position is within ladder range
	bool cond1 = y >= ladder.y - ladder.height / 2 - height / 2;
	bool cond2 = y <= ladder.y + ladder.height / 2 - height / 2;

	if (distance_x < ((this->width + ladder.width) / 3) && cond1 && cond2)
	{
		return true;
	}
	else {
		return false;
	}
}

//Mario is gaining score
void Mario::gainScore() { 
	score+=100; 
	resetPosition(); //He goes to his starting position
	
	//Play winning sound
	if (MUSIC_EFFECTS) {
		graphics::playSound("assets\\sounds\\winning.wav", SOUND_VOLUME, false);
	}
}
