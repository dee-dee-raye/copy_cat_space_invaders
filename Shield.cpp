#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "SpaceCrafts.h"
#include "Shield.h"
using namespace std;
#pragma once

Shield::Shield(int l, sf::RenderWindow& win)
{
	lives = l;

	beforeDie();
	if (!shieldTexture.loadFromFile("rainbow.png"))
	{
		cout << "Unable to load rainbow texture!" << endl;
		exit(EXIT_FAILURE);
	}
	theThing.setTexture(shieldTexture);

	loc.x = win.getSize().x / 2.0f;
	loc.y = win.getSize().y *(3.0 / 4.0f);
	theThing.setPosition(loc.x, loc.y);

}

sf::Texture Shield::getTextureForShield()
{
	sf::Texture temp;
	if (!temp.loadFromFile("shield.png"))
	{
		cout << "Unable to load shield texture!" << endl;
		exit(EXIT_FAILURE);
	}
	return temp;
}

void Shield::beforeDie()
{
	/*if (!shieldTexture.loadFromFile("shield.png"))
	{
		cout << "Unable to load shield texture!" << endl;
		exit(EXIT_FAILURE);
	}
	theThing.setTexture(shieldTexture);*/
}

void Shield::dieOne()
{
	/*if (!shieldTexture.loadFromFile("shield2.png"))
	{
		cout << "Unable to load shield2 texture!" << endl;
		exit(EXIT_FAILURE);
	}
	theThing.setTexture(shieldTexture);
	
	lives--;*/
}

void Shield::dieTwo()
{
	/*if (!shieldTexture.loadFromFile("shield3.png"))
	{
		cout << "Unable to load shield3 texture!" << endl;
		exit(EXIT_FAILURE);
	}
	theThing.setTexture(shieldTexture);

	lives--;*/
}

void Shield::dieThree()
{
	lives = 0;
}

void Shield::moveTheThing(sf::RenderWindow& win)
{
	if (lives == 3)
	{
		beforeDie();
		win.draw(theThing);
	}
	else if (lives == 2)
	{
		dieOne();
		win.draw(theThing);
	}
	else if (lives == 1)
	{
		dieTwo();
		win.draw(theThing);
	}
}

void Shield::checkForUserFire(sf::RenderWindow& win)
{
		moveTheProjectiles(win);
}

 