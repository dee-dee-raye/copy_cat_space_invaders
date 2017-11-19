#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "SpaceCrafts.h"
#include "Alien.h"
#pragma once


class TheHero: public SpaceCrafts
{
private:
	sf::Texture heroTexture; //to hold texture of hero/player
public:
	TheHero(int l, sf::RenderWindow& win);
	virtual void moveTheThing(sf::RenderWindow& win);
	void checkForUserFire(sf::RenderWindow& win, sf::Texture& missleTexture);
	bool checkForFire(list<Alien>& army);
	void resetHero(sf::RenderWindow& win);
};