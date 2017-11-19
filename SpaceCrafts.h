#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "Projectile.h"
#pragma once

struct Point
{
	float x;
	float y;
};

class SpaceCrafts 
{
protected:
	int lives;						//1 life for aliens, 3 lives for hero
	sf::Sprite theThing;			//sprite for alien and hero
	sf::FloatRect theThingBounds;	//bounds of sprite for alien and hero
	Point loc;						//original location of sprite	
	list<Projectile> weapons;		//list of missles for hero or list of bombs for alien
	list<Projectile>::iterator iterator;	//main iteraotr for missiles/bombs
	list<Projectile>::iterator iterTemp;	//temp iteraotor used to hold copies
public:
	SpaceCrafts();
	SpaceCrafts(int l);
	int getLives();
	void setLives(int l);
	Point getLoc();
	void setLoc(Point p);
	sf::Clock myClock;
	sf::Time myTime;
	virtual void moveTheThing(sf::RenderWindow& win) = 0;
	bool sustainedFire(list<Projectile>& enemy, list<Projectile>::iterator& temp);
	void fire(bool direction, sf::RenderWindow& win, sf::Texture& pTexture);
	void moveTheProjectiles(sf::RenderWindow& win);
	list<Projectile>* getWeaponsList();
};



