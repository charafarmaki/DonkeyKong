#include <iostream>
#include <random>
#include <string>
#include <vector>

#include <sgg/graphics.h>

//Include all necessary header files
#include "GameObject.h"
#include "Monkey.h"
#include "Mario.h"
#include "Pauline.h"
#include "Barrel.h"
#include "Stack.h"
#include "StackForMenu.h"
#include "FireBarrel.h"
#include "Hammer.h"
#include "IronGirder.h"
#include "Ladder.h"
#include "Lives.h"
#include "GameTitle.h"
#include "NewGameText.h"
#include "HelpText.h"
#include "ScoreText.h"
#include "HighscoreText.h"
#include "constants.h"

#include "Game.h" 

//Update the game state
void update(float t)
{
	Game* game = (Game*)graphics::getUserData();

	game->update(t); //Call update method of the game
}

//Draw the game
void draw()
{
	Game* game = (Game*)graphics::getUserData();

	game->draw();
}

int main()
{
	Game game; //Create game

	//Create a window with specified width, height, and title
	graphics::createWindow(game.window_width, game.window_height, "Donkey kong");

	game.init(); //Initialize the game

	//Bitmap assets
	const auto assets = graphics::preloadBitmaps("assets");
	for (const auto asset : assets) {
		std::cout << "PRELOADING : " << asset << std::endl;
	}

	//Use user data for graphics
	graphics::setUserData(&game);
	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	graphics::setCanvasSize(game.canvas_width, game.canvas_height);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	graphics::startMessageLoop();
	//Destroy the window after the message loop ends
	graphics::destroyWindow();

	//Successful execution
	return 0;
}
