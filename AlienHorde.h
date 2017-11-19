#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include <list>
#include "Alien.h"
#pragma once

class AlienHorde
{
private:
	list<Alien> horde;					//list of aliens, main component in class
	list<Alien>::iterator iteratorOne;	//main iterator to go through horde
	list<Alien>::iterator iteratorTwo;	//secondary iterator to go through horde
	int numOfAliens;					//number of aliens still in play
	sf::Clock myClock;					//used in determining bomb dropping
	sf::Time myTime;					//used in determingn bomb dropping
public:
	AlienHorde(sf::RenderWindow& win, bool level, sf::Texture& texture);
	bool move(sf::RenderWindow& win);
	void checkFire(sf::RenderWindow& win, list<Projectile>& enemyList);
	void checkForRandomFire(sf::RenderWindow& win, bool level, sf::Texture& texture1);
	list<Alien> getHorde();
	void reset(sf::RenderWindow& win);
	void resetForNewGame(sf::RenderWindow& win, bool level, sf::Texture& texture);
	void resetForLevelTwo(sf::RenderWindow& win, sf::Texture& texture);
	int getNum();
	//void loadAllTextures(sf::Texture& texture);
};