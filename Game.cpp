#include "Game.h"
void Game::init() {
	//
	// Construct main screen
	//
	mainMenuObjects.push_back(&title);
	mainMenuObjects.push_back(&menuMonkey);
	mainMenuObjects.push_back(&stack_left);
	mainMenuObjects.push_back(&stack_right);
	mainMenuObjects.push_back(&newGameText);

	//
	// Construct game over screen
	//
	mainMenuObjects.push_back(&title);
	mainMenuObjects.push_back(&menuMonkey);
	mainMenuObjects.push_back(&stack_left);
	mainMenuObjects.push_back(&stack_right);
	mainMenuObjects.push_back(&gameOverText);


	//
	// Construct game screen
	//
	graphics::Brush br;
	br.fill_color[0] = 0.1f;
	br.fill_color[1] = 0.1f;
	br.fill_color[2] = 0.1f;
	graphics::setWindowBackground(br);
	graphics::setFont("assets\\font.ttf");

	std::random_device seed;
	std::default_random_engine generator(seed());
	std::uniform_real_distribution<float> distribution(-1.0, 1.0);

	// Add all girders

	for (int i = 0; i < 16; i++) {
		IronGirder g(5.0f + i * 6, 28);
		girders.push_back(g);
	}

	for (int i = 0; i < 16; i++) {
		IronGirder g(10.0f + i * 6, 41);
		girders.push_back(g);
	}

	for (int i = 0; i < 16; i++) {
		IronGirder g(5.0f + i * 6, 54);
		girders.push_back(g);
	}

	for (int i = 0; i < 16; i++) {
		IronGirder g(10.0f + i * 6, 67);
		girders.push_back(g);
	}

	for (int i = 0; i < 16; i++) {
		IronGirder g(5.0f + i * 6, 80);
		girders.push_back(g);
	}

	for (int i = 0; i < 16; i++) {
		IronGirder g(5.0f + i * 6, 93);
		girders.push_back(g);
	}

	//Pauline's girder
	for (int i = 0; i < 5; i++) {
		IronGirder g(50.0f + i * 6, 14);
		girders.push_back(g);
	}

	// Add all ladders
	for (int i = 0; i < 2; i++) {
		Ladder l(38.0f + i * 7, 13.0f);
		ladders.push_back(l);
	}

	for (int i = 0; i < 2; i++) {
		Ladder l(38.0f + i * 7, 20.5f);
		ladders.push_back(l);
	}

	for (int i = 0; i < 1; i++) { // Pauline ladder
		Ladder l(70.0f + i * 40, 20.0f);
		l.height += 1.0f;
		ladders.push_back(l);
	}

	for (int i = 0; i < 1; i++) {
		Ladder l(85.0f + i * 30, 33.5f);
		ladders.push_back(l);
	}

	for (int i = 0; i < 2; i++) {
		Ladder l(15.0f + i * 35, 46.5f);
		ladders.push_back(l);
	}

	for (int i = 0; i < 2; i++) {
		Ladder l(30.0f + i * 55, 59.5f);
		ladders.push_back(l);
	}

	for (int i = 0; i < 2; i++) {
		Ladder l(15.0f + i * 35, 72.5f);
		ladders.push_back(l);
	}

	for (int i = 0; i < 1; i++) {
		Ladder l(85.0f, 85.5f);
		ladders.push_back(l);
	}


	//Lives
	for (int i = 0; i < 3; i++) {
		Lives l(90.0f + i * 4, 3.0f);
		hearts.push_back(l);
	}

	welcome();
}


//
// State changes
// 

void Game::welcome() {
	mode = MODE_MENU; // Set mode to main menu

	// Play background music if enabled
	if (MUSIC_ENABLED)
	{
		graphics::stopMusic();
		graphics::playMusic("assets\\music\\jungle.wav", SOUND_VOLUME, true);
	}
}

void Game::startGame() {
	mode = MODE_PLAYING; //Set mode to playing
	mario.lives = 3;     //Reset Mario's lives
	mario.score = 0;     //Reset Mario's score
	level = 1;           //Reset game level
	barrels.clear();

	//Add initial barrel if enabled
	if (ENABLE_BARRELS)
	{
		Barrel firstBarrel(BarrelPath::VerticalDrop);
		firstBarrel.x = 25;
		barrels.push_back(firstBarrel);
	}

	//Play in-game music if enabled
	if (MUSIC_ENABLED)
	{
		graphics::stopMusic();
		graphics::playMusic("assets\\music\\play.mp3", SOUND_VOLUME, true);
	}
}

void Game::quitGame() {
	mode = MODE_MENU; //Set mode to main menu

	//Update high score
	if (mario.score > high_score) {
		high_score = mario.score;
	}

	//Play background music
	if (MUSIC_ENABLED)
	{
		graphics::stopMusic();
		graphics::playMusic("assets\\music\\jungle.wav", SOUND_VOLUME, true);
	}
}

//Create game objects
void Game::draw()
{
	//
	// Common:
	//
	scoreText.draw(); //Draw score text
	highscoreText.draw(); //Draw high score text

	//Draw based on current game mode
	switch (mode) {
	case MODE_MENU:
		//Draw main menu objects
		for (const GameObject* object : mainMenuObjects) {
			object->draw();
		}
		newGameText.draw();

		break;
	case MODE_PLAYING:
		// Draw game objects
		monkey.draw();
		pauline.draw();
		for (Barrel& barrel : barrels) {
			barrel.draw();
		}
		helpText.draw();
		stack.draw();
		fire_barrel.draw();
		hammer.draw();

		for (auto& girder : girders) {
			girder.draw();
		}

		for (auto& ladder : ladders) {
			ladder.draw();
		}

		for (int i = 0; i < mario.lives; i++) {
			hearts[i].draw();
		}

		mario.draw();
		break;
	case MODE_GAME_OVER:
		// Draw game over objects
		for (GameObject* object : gameOverObjects) {
			object->draw();
		}
		break;
	}
}

//Update game objects based on current mode
void Game::update(float t)
{
	monkey.update(t);
	stack.update(t);
	helpText.update(t);

	helpText.x = pauline.x + 3;

	for (auto& girder : girders) {
		girder.update();
	}

	switch (mode) {
	case MODE_MENU:
		//Switch to game mode if space key is pressed
		if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
			startGame();
		}
		//Update main menu objects
		for (GameObject* object : mainMenuObjects) {
			object->update(t);
		}
		break;
	case MODE_PLAYING:
		//Quit game if Q key is pressed
		if (graphics::getKeyState(graphics::SCANCODE_Q)) {
			quitGame();
		}

		//Update Mario and Pauline
		mario.update(t, ladders);
		pauline.update(t);

		//Check collisions
		mario.checkCollision(monkey);
		mario.checkCollision(pauline);

		//Update and check collisions for barrels
		if (ENABLE_BARRELS) {
			for (Barrel& barrel : barrels) {
				barrel.update(t);
				mario.checkCollision(barrel);
			}

			//Remove barrels if they fall off the screen
			for (vector<Barrel>::iterator p = barrels.begin(); p != barrels.end(); ++p) {
				if (p->y > 120) {
					barrels.erase(p);
					cout << "Barrel removed from collection " << endl;
					break;
				}
			}

			//Add new barrel randomly if barrel count is low
			if (rand() % 250 < 1 && barrels.size() < 5) {
				BarrelPath path = (BarrelPath)(rand() % 4);
				Barrel barrel(path);
				barrels.push_back(barrel);
			}
		}
		break;
	case MODE_GAME_OVER:
		//Restart game if space key is pressed
		if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
			startGame();
		}
		//Update game over objects
		for (GameObject* object : mainMenuObjects) {
			object->update(t);
		}
		break;
	}

	//Quit game if player runs out of lives
	if (mario.lives == 0) {
		quitGame();
	}
}
