#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "SpaceCrafts.h"
#pragma once

class Shield : public SpaceCrafts
{
private:
	sf::Texture shieldTexture;
public:
	Shield(int l, sf::RenderWindow& win);
	static sf::Texture getTextureForShield();
	void beforeDie();
	void dieOne();
	void dieTwo();
	void dieThree();
	virtual void moveTheThing(sf::RenderWindow& win);
	virtual void checkForUserFire(sf::RenderWindow& win);
};

