#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "SpaceCrafts.h"
#pragma once


class Alien : public SpaceCrafts
{
private:
	//used in alien animation to change direction of movement
	int multiplierAlien;				
	const float ALIEN_DOWN_DISTANCE = 0.2f;	//downward distance
	const float ALIEN_SIDE_DISTANCE = 5.0f; //animation distance
	bool levelOfAlien;						//true is level one, false is level two
	int animationCount;						//used to control timing of animation
public:
	Alien(int l, sf::RenderWindow& win, bool level, sf::Texture& texture);
	Alien(int l, sf::RenderWindow& win, bool level, Point p, sf::Texture& texture);
	void levelUpAlien();
	void moveTheThing(sf::RenderWindow& win);
	bool moveDown(sf::RenderWindow& win);
	static sf::Texture loadTextureAndReturn();
};


