#include "HelpText.h"

#include <sgg/graphics.h>

HelpText::HelpText(float x, float y, float size) : GameObject(x,y,6.0f,2.5f), size(size)
{
	texture = "assets/iron_girder.png";

	prepareBrush();
}

void HelpText::prepareBrush()
{
	br.fill_color[0] = 1.0f; //Pink color
	br.fill_color[1] = 0.5f;
	br.fill_color[2] = 0.8f;
	br.fill_secondary_color[0] = 1.0f;
	br.fill_secondary_color[1] = 0.0f;
	br.fill_secondary_color[2] = 0.0f;
	br.outline_opacity = 0.0f; //Set outline opacity to 0 (no outline)
	br.texture = texture;
}



void HelpText::draw()
{	
	if (display) { //Check if help text should be displayed
		graphics::drawText(x, y, size, "HELP !", br); //Help! text
	}
} 

void HelpText::update(float t)
{
	age = age + t; //Age plus time that has passed 
	
	if (age > 700) { //If age greater than 700 milliseconds
		age = 0; //Reset age

		if (display == true) { //If help text is currently displayed
			display = false;   //Hide help text
		}
		else {
			display = true;    //Show help text
		}
	}
}
