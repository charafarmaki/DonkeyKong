#include <sgg/graphics.h> // Include necessary graphics library

#include "Barrel.h" // Include header file for Barrel class


Barrel::Barrel(BarrelPath path) : Enemy(20.0f, 26, 3, 2)
{
	speed = 0.03f; // Set initial speed
	this->path = path; // Assign provided path to the object

	texture[0] = "assets/side_barrel1.png"; // Load texture for left direction
	texture[1] = "assets/side_barrel2.png"; // Load texture for right direction

	prepareBrush(); // Prepare brush for drawing
}

void Barrel::prepareBrush() {
	// Set properties for the left direction brush
	br[0].fill_color[0] = 1.0f;
	br[0].fill_color[1] = 1.0f;
	br[0].fill_color[2] = 1.0f;
	br[0].outline_opacity = 0.0f;
	br[0].texture = texture[0];

	// Set properties for the left direction brush
	br[1].fill_color[0] = 1.0f;
	br[1].fill_color[1] = 1.0f;
	br[1].fill_color[2] = 1.0f;
	br[1].outline_opacity = 0.0f;
	br[1].texture = texture[1];
}


void Barrel::draw()
{
	// Draw the barrel based on its direction
	if (direction == Direction::Left) {
		graphics::drawRect(x, y, width, height, br[1]);
	}
	else {
		graphics::drawRect(x, y, width, height, br[0]);
	}
}

void Barrel::path1(float t) { // Normal path: drop at last ladder
	if (direction == Direction::Right) {
		if (x < 85) {
			x = x + speed * t;
		}
		else {
			direction = Direction::Down;
		}
	}
	else if (direction == Direction::Left) {
		if (x > 15) {
			x = x - speed * t;
		}
		else {
			direction = Direction::Down;
		}
	}
	else {
		y = y + speed * t;

		if (y > next_platform_y && x > 60) {
			direction = Direction::Left;

			next_platform_y = next_platform_y + 13;
		}

		if (y > next_platform_y && x < 50) {
			direction = Direction::Right;
			next_platform_y = next_platform_y + 13;
		}
	}
}

void Barrel::path2(float t) { // Alternative path: drop at various ladders
	if (direction == Direction::Right) {
		if (x < 85) {
			x = x + speed * t;
		}
		else {
			direction = Direction::Down;
		}
	}
	else if (direction == Direction::Left) {
		if (x > 50) {
			x = x - speed * t;
		}
		else {
			direction = Direction::Down;
		}
	}
	else {
		y = y + speed * t;

		if (y > next_platform_y && x > 60) {
			direction = Direction::Left; ;

			next_platform_y = next_platform_y + 13;
		}

		if (y > next_platform_y && x < 50) {
			direction = Direction::Right;
			next_platform_y = next_platform_y + 13;
		}
	}
}

void Barrel::path3(float t) { // Drop at end of platform
	if (direction == Direction::Right) {
		if (x < 85) {
			x = x + speed * t;
		}
		else {
			direction = Direction::Down;
		}
	}
	else if (direction == Direction::Left) {
		if (x > 5) {
			x = x - speed * t;
		}
		else {
			direction = Direction::Down;
		}
	}
	else {
		y = y + speed * t;

		if (y > next_platform_y && x > 60) {
			direction = Direction::Left;

			next_platform_y = next_platform_y + 13;
		}

		if (y > next_platform_y && x < 50) {
			direction = Direction::Right;
			next_platform_y = next_platform_y + 13;
		}
	}
}

void Barrel::path4(float t) { // Vertical
	y = y + speed * t;
}

void Barrel::update(float t)
{
	switch (path) {
	case FirstLadderDrop:
		path1(t); // Execute path1 if the specified path is FirstLadderDrop
		break;
	case RandomLadderDrop:
		path2(t);
		break;
	case PlatformDrop:
		path3(t);
		break;
	case VerticalDrop:
		path4(t);
		break;
	}
}
