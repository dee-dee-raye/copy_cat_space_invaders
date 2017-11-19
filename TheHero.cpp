#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "SpaceCrafts.h"
#include "TheHero.h"
#include "Alien.h"
#pragma once
using namespace std;


//===============================================================
// TheHero(int, RenderWindow: creates instance of fully 
// functioning hero/player
// parameters: 
// l: number of lives
// win: reference window to window in main
//===============================================================
TheHero::TheHero(int l, sf::RenderWindow& win)
{
	lives = l;	//set lives

	//load image to texture
	if (!heroTexture.loadFromFile("cat.png"))
	{
		cout << "Unable to load cat texture!" << endl;
		exit(EXIT_FAILURE);
	}
	theThing.setTexture(heroTexture);	//set texture to sprite
	
	//get and set the sprite's original location
	//in case of hero it is bottom center of window
	loc.x = win.getSize().x / 2.0f;
	loc.y = win.getSize().y *(7.0 / 8.0f);
	theThing.setPosition(loc.x, loc.y);
}

//===============================================================
// moveTheThing: move the hero/player based on arrow keys pressed
// parameters: 
// win: reference window to window in main
// return type: void
//===============================================================
void TheHero::moveTheThing(sf::RenderWindow& win)
{
	float width = win.getSize().x;			//width of window
	//flages to keep hero/player on screen
	bool theHeroIsOnScreenRight = false;	
	bool theHeroIsOnScreenLeft = false;

	//if on screen concering right side
	if (theThing.getPosition().x < width - 10)
	{
		theHeroIsOnScreenRight = true;
	}
	//if on screen concerning left side
	if (theThing.getPosition().x > 10)
	{
		theHeroIsOnScreenLeft = true;
	}
	
	const float DISTANCE = 5.0f;	//distance to move hero/player at a time
	//if left arrow key is pressed and hero/player is on screen concerning left side
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && theHeroIsOnScreenLeft)
	{
		//move left 5 pixels
		theThing.move(-DISTANCE, 0);
	}
	//if right arrow key is pressed and hero/player is on screen concerning right side
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && theHeroIsOnScreenRight)
	{
		// move right 5 pixels
		theThing.move(DISTANCE, 0);
	}
	
	//update state of screen of hero/player
	win.draw(theThing);
}

//===============================================================
// checkForUserFire: checks and reacts to user firing missiles
// parameters: 
// win: reference window to window in main
// missileTexture: reference to missile texture from main
// return type: void
//===============================================================
void TheHero::checkForUserFire(sf::RenderWindow& win, sf::Texture& missleTexture)
{
	//if spacebar is pressed
 	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//make a new missile/bomb and move others
		fire(true, win, missleTexture);
	}
	else
	{
		//move others
		moveTheProjectiles(win);
	}
}

//===============================================================
// checkForFire: check to see if the hero/player has hit any
// of alien sprite unit
// parameters: 
// army: list of Aliens to be checked
// return type: bool
// gotHit: true if an alien got hit, false if did not
//===============================================================
bool TheHero::checkForFire(list<Alien>& army)
{
	list<Alien>::iterator iter;			//to go through list
	list<Projectile>::iterator iter2;	//to hold missile that did hitting
	bool gotHit = false;
	
	//goes through aliens until out of aliens or found one hit
	for (iter = army.begin(); iter != army.end() && !gotHit; iter++)
	{
		//get bool of hit status and reference to missile that did the hitting
		gotHit=sustainedFire(*(iter->getWeaponsList()), iter2);
	}

	return gotHit;
}

//===============================================================
// resetHero: resets hero/player's position and lives
// parameters: 
// win: reference window to window in main
// return type: void
//===============================================================
void TheHero::resetHero(sf::RenderWindow& win)
{
	//reset lives
	lives = 3;
	//reset position
	loc.x = win.getSize().x / 2.0f;
	loc.y = win.getSize().y *(7.0 / 8.0f);
	theThing.setPosition(loc.x, loc.y);
}
