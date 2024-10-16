#include "Ladder.h"

#include "constants.h"

Ladder::Ladder(float x, float y) : GameObject(x,y,4.0f, 13.0f)
{
	texture = "assets/ladder.png";

	//Debug brush properties
	br_debug.fill_color[0] = 1.0f;
	br_debug.fill_color[1] = 1.0f;
	br_debug.fill_color[2] = 1.0f;
	br_debug.outline_opacity = 1.0f;
	br_debug.fill_opacity = 0.0f;

	prepareBrush();
}

void Ladder::prepareBrush()
{
	GameObject::prepareBrush();
	br.texture = texture;
}


void Ladder::draw()
{
	//Draw ladder
	graphics::drawRect(x, y, width, height, br);

	//Draw ladder border if BORDER_LADDERS flag is true
	if (BORDER_LADDERS) {
		graphics::drawRect(x, y, width, height, br_debug);
	}
}
