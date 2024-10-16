#include "Text.h"


Text::Text()
{
	prepareBrush();
}

void Text::prepareBrush()
{
	GameObject::prepareBrush();

	br.fill_secondary_color[0] = 1.0f;
	br.fill_secondary_color[1] = 0.0f;
	br.fill_secondary_color[2] = 0.0f;
	br.outline_opacity = 0.0f;
	size = 5;
}


void Text::draw() const
{
	graphics::drawText(x, y, size, text, br);
}
