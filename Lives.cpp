#include "Lives.h"

Lives::Lives(float x, float y) : GameObject(x,y,3.0f,2.5f)
{	
	texture = "assets/lives.png";
	
	prepareBrush();
}

void Lives::prepareBrush()
{
	GameObject::prepareBrush();
	br.texture = texture;
}
