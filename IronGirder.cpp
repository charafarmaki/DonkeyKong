#include "IronGirder.h"

IronGirder::IronGirder(float x, float y) : GameObject(x,y, 6.0f, 2.5f)
{
	texture = "assets/iron_girder.png";
	prepareBrush();
}

void IronGirder::prepareBrush()
{
	GameObject::prepareBrush();
	br.texture = texture;
}


void IronGirder::draw()
{
	graphics::drawRect(x, y, width, height, br);
}

void IronGirder::update()
{
}
