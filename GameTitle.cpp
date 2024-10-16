#include "GameTitle.h"


GameTitle::GameTitle(float x, float y) : GameObject(x,y, 55.0f, 14.5f) //Set width and height
{
	texture = "assets/title.png";
	
	prepareBrush();
}

void GameTitle::prepareBrush()
{
	GameObject::prepareBrush();
	br.texture = texture;
}
