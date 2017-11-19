#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include <list>
#include "SpaceCrafts.h"
#include "Projectile.h"
#pragma once


//===============================================================
// Projectile(bool, float, float, RenderWindow, Texture): 
// creates and draws a new missile/bomb
// parameters: 
// t: true for missile, and false for bomb
// x: orignal x location for missile/bomb
// y: orignal y location for missile/bomb
// win: reference window to window in main
// texture: missile/bomb texture from main
//===============================================================
Projectile::Projectile(bool t, float x, float y, sf::RenderWindow& win, sf::Texture& texture1)
{
	type = t;

	locX=x;
	locY = y;

	projectile.setTexture(texture1);
	projectile.setPosition(locX, locY);

	win.draw(projectile);
}

//===============================================================
// getBounds: gets missile/bomb's global bounds
// parameters: nothing
// return type: sf::FloatRect
// projectile.getGlobalBounds(): global bounds of missile/bomb
//===============================================================
sf::FloatRect Projectile::getBounds()
{
	return(projectile.getGlobalBounds());
}

//===============================================================
// getYPosition: get current y location of missile/bomb
// parameters: nothing
// return type: float
// projectil.getPosition().y: current y location of missile/bomb
//===============================================================
float Projectile::getYPosition()
{
	return(projectile.getPosition().y);
}

//===============================================================
// move: moves missile/bomb according to its type
// parameters: 
// win: reference window to window in main
// return type: void
//===============================================================
void Projectile::move(sf::RenderWindow& win)
{
	//if missile
	if (type) 
	{
		projectile.move(0, -UP_DISTANCE);
		
	}
	//if bomb
	else
	{
		projectile.move(0, DOWN_DISTANCE);
	}
	
	//update window from changes in missile/bomb movements
	win.draw(projectile);
}
