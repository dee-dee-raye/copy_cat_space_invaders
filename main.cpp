#include <iostream>
#include <cstdlib>
using namespace std;
#include <SFML/Graphics.hpp>
#include "SpaceCrafts.h"
#include "TheHero.h"
#include "Alien.h"
#include "Shield.h"
#include "AlienHorde.h"
#include "game.h"
#include "main.h"
#pragma once

void loadBackGroundTexture(sf::Texture& background);
void loadAlienLevelOneTexture(sf::Texture& alienOne);
void loadAlienLevelTwoTexture(sf::Texture& alienTwo);
void loadMissleTexture(sf::Texture& missile);
void loadBombLevelOneTexture(sf::Texture& bombOne);
void loadBombLevelTwoTexture(sf::Texture& bombTwo);

int main()
{
	// size of window of game, window
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Catton Candy!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// set up background with texture (image) and sprite (resizable)
	sf::Texture backgroundTexture;				
	loadBackGroundTexture(backgroundTexture);	
	sf::Sprite background;						
	background.setTexture(backgroundTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	// texture for level one alien. passed to game to use on all alien sprites.
	// during the first level.
	sf::Texture alienTextureLevelOne;
	loadAlienLevelOneTexture(alienTextureLevelOne);

	// texture for level one bombs. passed to game to use on all bombs dropped by aliens.
	//during first level.
	sf::Texture bombTextureLevelOne;
	loadBombLevelOneTexture(bombTextureLevelOne);

	// texture for missile. passed to game to use on all missiles sent by player
	sf::Texture missileTexture;
	loadMissleTexture(missileTexture);

	// texture for level two aline. passed to game to use on all alien sprites.
	// during the second level.
	sf::Texture alienTextureLevelTwo;
	loadAlienLevelTwoTexture(alienTextureLevelTwo);

	// texture for level two bombs. passed to game to use on all bombs dropped by aliens.
	// during second level.
	sf::Texture bombTextureLevelTwo;
	loadBombLevelTwoTexture(bombTextureLevelTwo);
	
	// holds the game itself with different fnctions for level one and two. sets up
	// sprites with their textures
	game theGame(window, true, alienTextureLevelOne, bombTextureLevelOne, missileTexture, 
		alienTextureLevelTwo, bombTextureLevelTwo);

	// while the game window is still open
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
	
		window.draw(background);		// draws the background sprite (field) 	
		theGame.play(window);			// runs one iteration of the game
		window.display();				// displays all the sprites from the game
	}


	return 0;
}


//===============================================================
// loadBackGroundTexture: loads image to background texture
// parameters: 
// background: texture of background
// return type: void
//===============================================================
void loadBackGroundTexture(sf::Texture& background)
{
	if (!background.loadFromFile("background.png"))
	{
		cout << "Unable to load background texture!" << endl;
		exit(EXIT_FAILURE);
	}
}

//================================================================
// loadAlienLevelOneTexture: loads image to level 1 alien texture
// parameters: 
// alienOne: texture of level 1 alien
// return type: void
//================================================================
void loadAlienLevelOneTexture(sf::Texture& alienOne)
{
	if (!alienOne.loadFromFile("butterfly.png"))
	{
		cout << "Unable to load butterfly texture!" << endl;
		exit(EXIT_FAILURE);
	}
}

//================================================================
// loadAlienLevelTwoTexture: loads image to level 2 alien texture
// parameters: 
// alienTwo: texture of level 2 alien
// return type: void
//================================================================
void loadAlienLevelTwoTexture(sf::Texture& alienTwo)
{
	if (!alienTwo.loadFromFile("unicorn.png"))
	{
		cout << "Unable to load unicorn texture!" << endl;
		exit(EXIT_FAILURE);
	}
}

//================================================================
// loadMissleTexture: loads image to missile texture
// parameters: 
// missile: texture of missile
// return type: void
//================================================================
void loadMissleTexture(sf::Texture& missile)
{
	if (!missile.loadFromFile("heart.png"))
	{
		cout << "Unable to load heart texture!" << endl;
		exit(EXIT_FAILURE);
	}
}

//================================================================
// loadBombLevelOneTexture: loads image to level 1 bomb texture
// parameters: 
// bombOne: texture of level 1 bomb
// return type: void
//================================================================
void loadBombLevelOneTexture(sf::Texture& bombOne)
{
	if (!bombOne.loadFromFile("flower.png"))
	{
		cout << "Unable to load butterfly texture!" << endl;
		exit(EXIT_FAILURE);
	}
}

//================================================================
// loadBombLevelTwoTexture: loads image to level 2 bomb texture
// parameters: 
// bombTwo: texture of level 2 bomb
// return type: void
//================================================================
void loadBombLevelTwoTexture(sf::Texture& bombTwo)
{
	if (!bombTwo.loadFromFile("donut.png"))
	{
		cout << "Unable to load unicorn texture!" << endl;
		exit(EXIT_FAILURE);
	}
}