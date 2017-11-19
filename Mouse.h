#include <iostream>
#include <cstdlib>
using namespace std;
#include <SFML/Graphics.hpp>
#pragma once

class Mouse
{
private:
	sf::Mouse myMouse;	//user's mouse
public:
	Mouse();
	float getYPoint(sf::RenderWindow& win);
	float getXPoint(sf::RenderWindow& win);
	bool intersects(sf::FloatRect bounds, sf::RenderWindow& win);
};