#include "Level.h"
#include<iostream>
/*
TODO:
1. write a code to move the cirle towards the right - DONE

2.Check if the circle reached the right side of the screen

3. if it has reached then move towards the left.

4. When it reaches the left then move towards the right again.
*/
Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	circle.setRadius(15);
	circle.setPosition(window->getSize().x - 100, 300);
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineColor(sf::Color::Magenta);
	circle.setOutlineThickness(2.f);

	speed = 100.f;


	circle2.setRadius(10);
	circle2.setPosition(200, 400);
	circle2.setFillColor(sf::Color::Red);
	circle2.setOutlineColor(sf::Color::Yellow);
	circle2.setOutlineThickness(2.f);


}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	MovingShape();
}


// Update game objects
void Level::update(float dt)
{

	std::cout << window->getSize().x<<"\n";
	std::cout << circle.getPosition().x << "\n";
	float windX, circX, circX2;
	windX = window->getSize().x;
	circX = circle.getPosition().x;
	circX = circX + 30;
	circX2 = circX - 30;

	if (circX >= 1200)
	{
		std::cout << "Reached" << "\n";
		speed = -100.f;
	}

	if (circX2 <= 0)
	{
		std::cout << "Reached" << "\n";
		speed = 100.f;
	}

	//update/ move circle
	circle.move(speed * dt, 0);
	circle2.move(speedLeft * dt , speedUP * dt );

}

/*
1. Make Up arrow move circle up the screen
2. Make Down arrow move circle down the screen
3. Make Left arrow move circle LEFT the screen
4. Make right arrow move circle right the screen
5. if circle reaches boundaries dont let it move

*/

void Level::MovingShape() {


	speedLeft = 0.f;
	speedUP = 0.f;

	if (input->isKeyDown(sf::Keyboard::Right))
	{
		speedLeft = 100.f;
		input->setKeyUp(sf::Keyboard::Right);
	}

	else if (input->isKeyDown(sf::Keyboard::Left))
	{
		speedLeft = -100.f;
		input->setKeyUp(sf::Keyboard::Left);
	}

	else if (input->isKeyDown(sf::Keyboard::Up))
	{
		speedUP = -100.f;
		input->setKeyUp(sf::Keyboard::Up);
	}

	else if (input->isKeyDown(sf::Keyboard::Down))
	{
		speedUP = 100.f;
		input->setKeyUp(sf::Keyboard::Down);
	}






}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);
	window->draw(circle2);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}