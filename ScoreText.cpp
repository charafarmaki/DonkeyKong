#include "ScoreText.h"

#include <string>

using namespace std;

ScoreText::ScoreText(float x, float y, float size, string label, int* score) : GameObject(x, y, 6.0f,2.5f), size(size), label(label), score(score)
{	
	prepareBrush();
}

void ScoreText::draw()
{
	graphics::drawText(x, y, size, label + "   " + to_string(*score), br);
}
