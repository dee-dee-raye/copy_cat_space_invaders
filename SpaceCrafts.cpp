#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "SpaceCrafts.h"
#include "Projectile.h"


//===============================================================
// SpaceCrafts(): only sets lives to 0
// parameters: nothing
//===============================================================
SpaceCrafts::SpaceCrafts()
{
	lives = 0;
}

//===============================================================
// SpaceCrafts(int): only sets lives to int given 
// parameters: 
// l: int number to set lives to
//===============================================================
SpaceCrafts::SpaceCrafts(int l)
{
	lives = l;
}

//===============================================================
// getLives: gets lives of hero or alien
// parameters: nothing
// return type: int
// lives: current number of lives of hero or alien
//===============================================================
int SpaceCrafts::getLives()
{
	return lives;
}

//===============================================================
// setLives: sets lives of hero or alien to new value
// parameters: 
// l: int number to set lives to
// return type: void
//===============================================================
void SpaceCrafts::setLives(int l)
{
	lives = l;
}

//===============================================================
// getLoc: returns orginal location of sprite of hero or alien
// parameters: 
// return type: Point (struct of float x and float y)
// loc: orignal location of sprite of hero or alien
//===============================================================
Point SpaceCrafts::getLoc()
{
	return loc;
}

//===============================================================
// setLoc: resets value of original location
// parameters: 
// p: Point to reset original location with
// return type: void
//===============================================================
void SpaceCrafts::setLoc(Point p)
{
	loc = p;
	theThing.setPosition(loc.x, loc.y);
}

//===============================================================
// fire: creates new missile of bullet and moves all others
// parameters: 
// direction: true for missile, false for bomb
// win: reference window to window in main
// pTexture: texture of a missile or a bomb
// return type: void
//===============================================================
void SpaceCrafts::fire(bool direction, sf::RenderWindow& win, sf::Texture& pTexture)
{
	//get current location of sprite that called fire
	Point p;
	p.x=theThing.getPosition().x;
	p.y=theThing.getPosition().y;

	//get time passed since last call
	myTime = myClock.getElapsedTime();
	//if it has been half a second since the last missile/bomb
	//launched
	if(myTime.asSeconds() > .5)
	{
		//add new missile/bomb to list
		weapons.push_front(Projectile(direction, p.x, p.y, win, pTexture));
		//restart the time
		myClock.restart();
	}
	
	//move the other bombs/missiles
	moveTheProjectiles(win);
}

//===============================================================
// moveTheProjectiles: moves all bombs/missiles in list
// parameters: 
// win: reference window to window in main
// return type: void
//===============================================================
void SpaceCrafts::moveTheProjectiles(sf::RenderWindow& win)
{
	bool foundOne = false;		//true is a missles/bomb is outside the window

	//goes through list of missles/bombs
	for (iterator = weapons.begin(); iterator != weapons.end(); iterator++)
	{
		//move indivdual element
		iterator->move(win);
		//if element(missile/bomb) is outside of window
		if (!(iterator->getYPosition() < win.getSize().y && iterator->getYPosition() > 0))
		{
			foundOne = true;
		}
	}
	if (foundOne)
	{
		//get rid of oldest element, because
		//it would have reached the outside of
		//the window first, so it must be the one
		//the set off the trigger
		weapons.pop_back();
	}
}

//===============================================================
// sustainedFire: handles if sprite was hit by other sprite's
// missile/bomb
// parameters: 
// enemy: list of other sprite's missiles/bombs
// temp: iterator to be set to projectile that did the hitting
// so that it can returned through reference
// return type: bool
// gotHit: false if did not get hit and true if did get hit
//===============================================================
bool SpaceCrafts::sustainedFire(list<Projectile>& enemy,list<Projectile>::iterator& temp)
{
	bool gotHit = false;				//false if not hit, true if hit
	sf::FloatRect projectileBounds;		//to hold global bounds of individual missiles/bombs
	//global bounds of sprite (hero/alien)
	sf::FloatRect spaceCraftBounds = theThing.getGlobalBounds();
	//goes through list of other sprite's missiles/bombs
	for (iterator = enemy.begin(); iterator != enemy.end() && !gotHit; iterator++)
	{
		projectileBounds = iterator->getBounds();	//gets global bounds of current element
		//if bounds of sprite intersects with element's bounds
		if (spaceCraftBounds.intersects(projectileBounds))
		{
			temp = iterator;	//save element (missle/bomb) that did the hitting
			gotHit = true;		
			lives--;			//take away a life
		}
	}
	return gotHit;

}

//===============================================================
// getWeapondsList: gets pointer to sprite's list 
// of missiles/bombs
// parameters: 
// return type: list<Projectile>*
// &weapons: address to list of missiles/bombs of sprite
//===============================================================
list<Projectile>* SpaceCrafts::getWeaponsList()
{
	return &weapons;
}



