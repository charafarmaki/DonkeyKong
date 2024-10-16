#include <sgg/graphics.h>

#include "Monkey.h"

//Constructor to initialize Monkey with position and dimensions
Monkey::Monkey(float x, float y) : Enemy(x,y,12,12)
{	
	texture[0] = "assets/monkey1.png";
	texture[1] = "assets/monkey2.png";
	texture[2] = "assets/monkey3.png";

	prepareBrush();
}

void Monkey::prepareBrush()
{
	for (int i = 0; i < 3; i++) {
		br[i].fill_color[0] = 1.0f;
		br[i].fill_color[1] = 1.0f;
		br[i].fill_color[2] = 1.0f;
		br[i].outline_opacity = 0.0f;
		br[i].texture = texture[i];
	}	
}


void Monkey::draw() const
{
	//Current frame based on Monkey's age
	int state = ((int) age/300) % 3;

	if (state == 0) {
		graphics::drawRect(x, y, width, height, br[0]);
	}
	else if (state == 1) {
		graphics::drawRect(x, y, width, height, br[1]);
	}
	else {
	 graphics::drawRect(x, y, width, height, br[2]);
	}
}

//Update monkey
void Monkey::update(float t)
{
	//Monkey's age
	age = age + t;

}
