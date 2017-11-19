#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include <list>
#include "Alien.h"
#include "AlienHorde.h"
#pragma once

//===============================================================
// AlienHorde(RenderWindow, bool,Texture): creates a list of
// aliens
// parameters: 
// win: reference window to window in main
// level: true for level one, false for level two
// texture: texture of alien from main
//===============================================================
AlienHorde::AlienHorde(sf::RenderWindow& win, bool level, sf::Texture& texture)
{
	Point p;
	for (int i = 0; i < 10; i++)
	{
		p.x = win.getSize().x*(i / 10.0f);
		p.y = win.getSize().y *(1.0 / 8.0f);
		
		horde.push_back(Alien(1, win, level, p, texture));
	}
	numOfAliens = 10;
}

//===============================================================
// move: moves horde downwards by moving each alien individually
// parameters: 
// win: reference window to window in main
// return type: bool
// reachedBotton: true if one of aliens reached bottom of screen
// where hero/player stays, false if not
//===============================================================
bool AlienHorde::move(sf::RenderWindow& win)
{
	bool reachedBottom = false;

	for (iteratorOne = horde.begin(); iteratorOne != horde.end(); iteratorOne++)
	{
			reachedBottom=iteratorOne->moveDown(win);
			iteratorOne->moveTheThing(win);
	}
	return reachedBottom;
}

//===============================================================
// checkForRandomFire: controls random bomb dropping of aliens
// parameters: 
// win: reference window to window in main
// level: true for level one, false for level two
// bombTexture: texture of bomb from main
// return type: void
//===============================================================
void AlienHorde::checkForRandomFire(sf::RenderWindow& win, bool level, sf::Texture& bombTexture)
{
	//get random number that will corrospond to alien that drops the bomb
	srand(time(0));
	float random = rand() % numOfAliens;
	//tracks which element loop is on
	int count = 0;
	//gets time that has passed to use to see if enough time has pased for a bomb to deploy
	myTime = myClock.getElapsedTime();
	//goes through list of aliens
	for (iteratorOne = horde.begin(); iteratorOne != horde.end() && count<=random; iteratorOne++)
	{
		//updates element count
		count++;
		//move that alien's bombs
		iteratorOne->moveTheProjectiles(win);
		//make a copy of current iterator 
		//to have when fall out of loop
		iteratorTwo = iteratorOne;
	}
	//if on level one
	if (level)
	{
		//if it has been more of a second since the last bomb was created
		if (myTime.asSeconds() > 1)
		{
			//restart clock
			myClock.restart();
			//drop a bomb from that alien
			iteratorTwo->fire(false, win, bombTexture);
		}
	}
	//if on second level
	else
	{
		//if its been less than half a second since the last bomb was dropped
		if (myTime.asSeconds() > .5)
		{
			//restart clock
			myClock.restart();
			//drop a bomb from that alien
			iteratorTwo->fire(false, win, bombTexture);
		}
	}

	//now go through the rest of the aliens
	for (iteratorOne = iteratorTwo; iteratorOne != horde.end(); iteratorOne++)
	{
		//move this alien's bombs
		iteratorOne->moveTheProjectiles(win);
	}

}

//===============================================================
// checkFire: check and react to if the aliens have sustained
// damages
// parameters: 
// win: reference window to window in main
// enemyList: list hero/player's missiles
// return type: void
//===============================================================
void AlienHorde::checkFire(sf::RenderWindow& win, list<Projectile>& enemyList)
{
	//iterator to go through enemy list
	list<Projectile>::iterator iter;
	//true if an alien has sustained damages, false if not
	bool found = false;

	//true if it found a damaged alien, false if not.
	//must make a complete pass with out damages to 
	//get out of loop
	bool keepGoing = true;
	while (keepGoing)
	{
		keepGoing = false;
		for (iteratorOne = horde.begin(); iteratorOne != horde.end() && !found; iteratorOne++)
		{
			//if alien was damaged
			if (iteratorOne->sustainedFire(enemyList, iter))
			{
				//have to go at least another run through loop
				keepGoing = true;
				//did find a damaged one
				found = true;
				//copy the damaged one's iterator to save it when fallen out of loop
				iteratorTwo = iteratorOne;
			}
		}
		//if a damaged one was found
		if (found)
		{
			//erase missile from the list of hero's missile
			enemyList.erase(iter);
			horde.erase(iteratorTwo);	//erase damaged alien
			found = false;				//reset found
			numOfAliens--;				//update alien count
		}
	}
	
}

//===============================================================
// getHorde: gets the list of aliens
// parameters: nothing
// return type: list<Alien>
// horde: list of aliens
//===============================================================
list<Alien> AlienHorde::getHorde()
{
	return horde;
}

//===============================================================
// reset: move surviving to top of window and clear out their
// bombs
// parameters: 
// win: reference window to window in main
// return type: void
//===============================================================
void AlienHorde::reset(sf::RenderWindow& win)
{
	Point p;						//to hold new original location for aliens
	iteratorOne = horde.begin();	//iterator to go through the aliens
	list<Projectile>* temp;			//to point to list of alien's bombs
	
	//go through aliens until reached num of aliens left or the list is empty
	for (float i = 0; i < numOfAliens && iteratorOne!=horde.end(); i++)
	{
		//work out new position based on number of aliens left
		p.x = win.getSize().x*(i / (numOfAliens));
		p.y = win.getSize().y *(1.0 / 8.0f);
		iteratorOne->setLoc(p);
		
		iteratorOne++;		// progress through list
	}
	//go through aliens
	for (iteratorOne = horde.begin(); iteratorOne != horde.end(); iteratorOne++)
	{
		//get list of bombs from alien
		temp=iteratorOne->getWeaponsList();
		//clear that list
		temp->clear();
	}
}

//===============================================================
// resetForNewGame: reset aliens completely in level 1 fashion
// parameters: 
// win: reference window to window in main
// level: true for level one, fasle for level two
// texture: alien texture from main
// return type: void
//===============================================================
void AlienHorde::resetForNewGame(sf::RenderWindow& win, bool level, sf::Texture& texture )
{
	//clear out current aliens
	horde.clear();

	//get new original locations and add alien to list
	Point p;
	for (int i = 0; i < 10; i++)
	{
		p.x = win.getSize().x*(i / 10.0f);
		p.y = win.getSize().y *(1.0 / 8.0f);

		horde.push_back(Alien(1, win, level, p, texture));
	}

	numOfAliens = 10;	//reset number of living aliens
}

//===============================================================
// getNum: gets number of aliens still in play
// parameters: nothing
// return type: int
// noOfAlens: number of aliens still in play
//===============================================================
int AlienHorde::getNum()
{
	return numOfAliens;
}

//===============================================================
// resetForLevelTwo: reset aliens completely in level 2 fashion
// parameters: 
// win: reference window to window in main
// texture: alien texture from main
// return type: void
//===============================================================
void AlienHorde::resetForLevelTwo(sf::RenderWindow& win, sf::Texture& texture)
{
	//clear the list of aliens out
	horde.clear();

	//set up new original location for aliens and add alien to list
	Point p;
	for (int i = 0; i < 10; i++)
	{
		p.x = win.getSize().x*(i / 10.0f);
		p.y = win.getSize().y *(1.0 / 8.0f);

		horde.push_back(Alien(1, win, false, p, texture));
	}

	//reset number of aliens
	numOfAliens = 10;
}

