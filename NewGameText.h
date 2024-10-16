#pragma once

#include <iostream>
#include <string>
#include <sgg/graphics.h>

#include "Text.h"

using namespace std;

class NewGameText : public Text
{
public:
	NewGameText(float x = 29, float y = 65, float size = 3);
};
