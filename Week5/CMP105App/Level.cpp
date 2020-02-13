#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	zombie.setInput(input);
	zombie.setSpeed(80);
	zombie.setPosition(200, 150);
	zombie.setSize(sf::Vector2f(55, 108));
	zombieTexture.loadFromFile("gfx/animZombie.png");
	zombie.setTexture(&zombieTexture);

	mario.setInput(input);
	mario.setPosition(200, 300);
	mario.setSize(sf::Vector2f(15, 21));
	marioTexture.loadFromFile("gfx/MarioSheetT.png");
	mario.setTexture(&marioTexture);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	zombie.handleInput(dt);
	mario.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	zombie.update(dt);
	mario.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(zombie);
	window->draw(mario);
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