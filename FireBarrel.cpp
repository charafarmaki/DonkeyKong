#include <sgg/graphics.h>

#include "FireBarrel.h"


FireBarrel::FireBarrel() : GameObject(8.0f, 87.5f, 6, 9)
{
	texture = "assets/firebarrel.png"; //Set path for the fire barrel's texture

	prepareBrush();
}

void FireBarrel::prepareBrush()
{
	GameObject::prepareBrush();
	br.texture = texture;
}
