#include <sgg/graphics.h>

#include "Hammer.h"

Hammer::Hammer() : GameObject(90.0f, 71.0f, 5, 5)
{
	texture = "assets/hammer.png";

	prepareBrush();
}

void Hammer::prepareBrush()
{
	GameObject::prepareBrush();
	br.texture = texture;
}
