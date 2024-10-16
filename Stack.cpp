#include <sgg/graphics.h>

#include "Stack.h"

Stack::Stack(float x, float y) : GameObject(x, y, 10, 15)
{
	texture = "assets/stack.png";

	prepareBrush();
}

void Stack::prepareBrush()
{
	GameObject::prepareBrush();
	br.texture = texture;
}
