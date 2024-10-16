#include "GameObject.h"

//Constructor for GameObject class
GameObject::GameObject(float x, float y, float width, float height) :x(x), y(y), width(width), height(height){

}

//Draw method for GameObject class
void GameObject::draw() const {
	graphics::drawRect(x, y, width, height, br);
}

//Update method for GameObject class
void GameObject::update(float t) {

}

void GameObject::prepareBrush() {
	br.fill_color[0] = 1.0f; //Set fill color to white
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	br.outline_opacity = 0.0f; //Set outline opacity to 0 (no outline)
}
