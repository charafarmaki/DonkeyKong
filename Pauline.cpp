#include <sgg/graphics.h>

#include "Pauline.h"

Pauline::Pauline() : Friend(62.0f,10.5f, 3, 5)
{
	texture[0] = "assets/girl1.png";
	texture[1] = "assets/girl2.png";

	prepareBrush();	
}

void Pauline::prepareBrush()
{
	br[0].fill_color[0] = 1.0f;
	br[0].fill_color[1] = 1.0f;
	br[0].fill_color[2] = 1.0f;
	br[0].outline_opacity = 0.0f;
	br[0].texture = texture[0];

	br[1].fill_color[0] = 1.0f;
	br[1].fill_color[1] = 1.0f;
	br[1].fill_color[2] = 1.0f;
	br[1].outline_opacity = 0.0f;
	br[1].texture = texture[1];
}


void Pauline::draw()
{
	if (going_left) {
		graphics::drawRect(x, y, width, height, br[1]);
	}
	else {
		graphics::drawRect(x, y, width, height, br[0]);
	}
}

//Update Pauline's position
void Pauline::update(float t)
{ 
	//Moving right until reaching a certain position
	if (going_right) {
		if (x < 70) {
			x = x + speed*t;
		}
		//If reached, change direction to left
		else {
			going_left = true;
			going_right = false;
		}
	}
	//Moving left until reaching a certain position
	else {
		if (x > 50) {
			x = x - speed * t;
		}
		//If reached, change direction to right
		else {
			going_left = false;
			going_right = true;
		}
	}
}
