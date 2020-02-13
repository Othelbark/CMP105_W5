#include "Mario.h"

Mario::Mario()
{
	//initalise walking animation
	walkingAni.addFrame(sf::IntRect(0, 0, 15, 21));
	walkingAni.addFrame(sf::IntRect(15, 0, 15, 21));
	walkingAni.addFrame(sf::IntRect(30, 0, 15, 21));
	walkingAni.addFrame(sf::IntRect(45, 0, 15, 21));
	walkingAni.setFrameSpeed(0.1f);

	swimingAni.addFrame(sf::IntRect(0, 21, 16, 20));
	swimingAni.addFrame(sf::IntRect(16, 21, 16, 20));
	swimingAni.addFrame(sf::IntRect(32, 21, 16, 20));
	swimingAni.setFrameSpeed(0.1f);

	crouchingAni.addFrame(sf::IntRect(0, 41, 16, 20));
	crouchingAni.addFrame(sf::IntRect(16, 41, 16, 20));
	crouchingAni.setFrameSpeed(0.1f);


	currentAni = &walkingAni;
	setTextureRect(currentAni->getCurrentFrame());

	directionVector = sf::Vector2f(0, 0);
	isWalking = false;
	isSwiming = false;
	isCrouching = false;
	isFlipped = false;
	speed = 120;
}
Mario::~Mario()
{
}

void Mario::handleInput(float dt)
{
	//get direction from input
	if (input->isKeyDown(sf::Keyboard().A))
	{
		isWalking = true;
		isFlipped = true;
		directionVector.x = -1;
	}
	else if (input->isKeyDown(sf::Keyboard().D))
	{
		isWalking = true;
		isFlipped = false;
		directionVector.x = 1;
	}
	else
	{
		isWalking = false;
		directionVector.x = 0;
	}

	setVelocity(directionVector * speed);

	//start / stop swiming from input
	if (input->isKeyDown(sf::Keyboard().Space))
	{
		isSwiming = !isSwiming;
		input->setKeyUp(sf::Keyboard().Space);
	}

	//start / stop crouching from input
	if (input->isKeyDown(sf::Keyboard().LControl))
	{
		isCrouching = true;
	}
	else
	{
		isCrouching = false;
		crouchingAni.reset();
	}
}

void Mario::update(float dt)
{
	//find correct animation
	if (isCrouching)
	{
		setSize(sf::Vector2f(16, 20));
		currentAni = &crouchingAni;
	}
	else if (isSwiming)
	{
		setSize(sf::Vector2f(16, 20));
		currentAni = &swimingAni;
	}
	else
	{
		setSize(sf::Vector2f(15, 21));
		currentAni = &walkingAni;
	}

	//animate if in motion
	if (isWalking)
	{
		//Move based on velocity
		move(velocity * dt);

		//Animate
		currentAni->animate(dt);
	}

	//set current frame and direction
	currentAni->setFlipped(isFlipped);
	setTextureRect(currentAni->getCurrentFrame());
}
