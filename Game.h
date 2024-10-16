#pragma once

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

enum GameMode {
	MODE_MENU,
	MODE_PLAYING,
	MODE_GAME_OVER
};

class Game {
private:
	GameMode mode = GameMode::MODE_MENU; //Current game mode
public:
	//
	// Common state
	//
	
	int high_score = 0;
	int level = 1; //Current game level
	ScoreText scoreText = ScoreText(2, 4, 2, "Score", &mario.score); //Score text
	ScoreText highscoreText = ScoreText(40, 4, 2, "High score", &high_score); //High score text

	//
	// Main menu state
	//
	vector<GameObject*> mainMenuObjects; //Vector to store main menu objects

	GameTitle title;
	Monkey menuMonkey = Monkey(48.5f, 48.0f); //Monkey object for main menu
	Stack stack_left = Stack(34.5f, 48.0f);   //Stack object for left side in main menu
	Stack stack_right = Stack(64.5f, 48.0f);
	NewGameText newGameText;

	//
	//  Game over state
	//
	vector<GameObject*> gameOverObjects;
	NewGameText gameOverText;


	//
	// Game state
	// 
	Monkey monkey = Monkey(25.0f, 21); //Objects for gameplay
	Mario mario;
	Pauline pauline;
	vector<Barrel> barrels; //Vector to store barrels
	Stack stack;
	HelpText helpText;

	FireBarrel fire_barrel;
	Hammer hammer;
	vector<IronGirder> girders;
	vector<Ladder> ladders;
	vector<Lives> hearts;

	int window_width = 1200; //Window dimensions
	int window_height = 900;

	float canvas_width = 100.0f; //Canvas dimensions
	float canvas_height = 100.0f;

	//Initialize game state and objects
	void init();

	//
	// State changes
	// 

	//Display welcome message and set game mode to main menu
	void welcome();

	//Start the game and set game mode to playing
	void startGame();

	//Quit the game and set game mode to main menu
	void quitGame();


	//
	// Graphics
	// 

	//Create objects
	void draw();

	//Update objects
	void update(float t);

};

