#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include <list>
#pragma once


class Projectile
{
private:
	sf::Sprite projectile;			//sprite for bombs and missiles
	sf::Texture projectileTexture;	//texture for bombs and missiles
	float locX;						// original x locaion
	float locY;						//original y locaition
	bool type;						// true for missile, false for bomb
	const float DOWN_DISTANCE = 3.0f;	//how far to move at a time for bombs
	const float UP_DISTANCE = 4.0f;		//how far to move at a time for missiles
public:
	Projectile(bool t, float x, float y, sf::RenderWindow& win, sf::Texture& texture1);
	sf::FloatRect getBounds();
	float getYPosition();
	void move(sf::RenderWindow& win);

};