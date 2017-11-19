#include <iostream>
#include <cstdlib>
using namespace std;
#include <SFML/Graphics.hpp>
#include "Mouse.h"
#pragma once

//===============================================================
// Mouse(): sets up myMouse
// parameters: nothing
//===============================================================
Mouse::Mouse()
{
	myMouse;
}

//===============================================================
// getYPoint: gets y position of mouse when mouse is clicked
// otherwise returns -1
// parameters: 
// win: reference window to window in main
// return type: float 
// yPoint: if mouse is clicked y position of mouse, if mouse
// is not clicked returns -1
//===============================================================
float Mouse::getYPoint(sf::RenderWindow& win)
{
	float yPoint = -1;
	if (myMouse.isButtonPressed(sf::Mouse::Button::Left))
	{
		yPoint= myMouse.getPosition(win).y;
	}
	return yPoint;
}

//===============================================================
// getXPoint: gets x position of mouse when mouse is clicked
// otherwise returns -1
// parameters: 
// win: reference window to window in main
// return type: float 
// xPoint: if mouse is clicked x pooint of mouse, if mouse
// is not clicked returns -1
//===============================================================
float Mouse::getXPoint(sf::RenderWindow& win)
{
	float xPoint = -1;
	if (myMouse.isButtonPressed(sf::Mouse::Button::Left))
	{
		xPoint = myMouse.getPosition(win).x;
	}
	return xPoint;
}

//===============================================================
// intersects: determines if mouse position
// intersects bounds of sprite passed to it
// parameters: 
// bounds: global bounds of sprite to check with
// win: reference window to window in main
// return type: bool
// contains: if mouse bounds intersect passed bounds true,
// othewise false.
//===============================================================
bool Mouse::intersects(sf::FloatRect bounds, sf::RenderWindow& win)
{
	bool contains = false;
	float x = getXPoint(win);
	float y = getYPoint(win);
	if (bounds.contains(x, y))
	{
		contains = true;
	}
	return contains;
}
