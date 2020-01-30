#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();
	void MovingShape();
	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	//moving circle vars
	sf::CircleShape circle;
	sf::CircleShape circle2;
	float speed;
	float speedLeft;
	float speedUP;
	//moving triangle vars
	
};