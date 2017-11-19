#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "SpaceCrafts.h"
#include "Alien.h"
using namespace std;
#pragma once


//===============================================================
// Alien(int l, RenderWindow, bool, Texture): creates basic alien
// for use in testing
// parameters: 
// l: number of lives
// win: reference window to window in main
// level: true for level one, false for level two
// texture: texture of alien from main
//===============================================================
Alien::Alien(int l, sf::RenderWindow& win, bool level, sf::Texture& texture)
{
	levelOfAlien = level;

	//for individual alien animation
	animationCount = 0;
	
	//set texture to alien sprite
	theThing.setTexture(texture);

	//set standard position
	loc.x = win.getSize().x / 2.0f;
	loc.y = win.getSize().y *(1.0 / 8.0f);
	theThing.setPosition(loc.x, loc.y);

	multiplierAlien = -1;
}

//===============================================================
// Alien(int l, RenderWindow, bool, Point, Texture): creates 
// basic alien for use in testing
// parameters: 
// l: number of lives
// win: reference window to window in main
// level: true for level one, false for level two
// texture: texture of alien from main
//===============================================================
Alien::Alien(int l, sf::RenderWindow& win, bool level, Point p, sf::Texture& texture)
{
	
	levelOfAlien = level;
	//for individual alien animation
	animationCount = 0;

	lives = l;		//set lives

	//set texture
	theThing.setTexture(texture);

	//set position with given position
	loc.x = p.x;
	loc.y = p.y;
	theThing.setPosition(loc.x, loc.y);

	multiplierAlien = -1;
}

//===============================================================
// moveTheThing: controls the simple side to side animation
// parameters: 
// win: reference window to window in main
// return type: void
//===============================================================
void Alien::moveTheThing(sf::RenderWindow& win)
{
		//if first second passed
		if (animationCount == 60)
		{
			//shift to the side
			theThing.move(multiplierAlien*(ALIEN_SIDE_DISTANCE), 0);
			//switch multiplier
			multiplierAlien = multiplierAlien*-1;
		}
		//if second second passed
		else if (animationCount == 120)
		{
			//sift to the other side
			theThing.move(multiplierAlien*(ALIEN_SIDE_DISTANCE), 0);
			//switch multiplier
			multiplierAlien = multiplierAlien*-1;
			//restart count
			animationCount = 0;
		}

	animationCount++;
	
	//draw change from animation
	win.draw(theThing);
	
}

//===============================================================
// moveDown: moves aliens down and also checks if they reached
// the bottom
// parameters: 
// win: reference window to window in main
// return type: bool
// reachedBottom: true if reached bottom, false if did not
//===============================================================
bool Alien::moveDown(sf::RenderWindow& win)
{
	bool reachedBottom = false;
	//if at area above bottome area where hero/player is
	if (!(theThing.getPosition().y > win.getSize().y*(.80)))
	{
		//move down
		theThing.move(0, ALIEN_DOWN_DISTANCE);
	}
	else
	{
		reachedBottom = true;
	}

	//update window with change from movement
	win.draw(theThing);

	return reachedBottom;
}





