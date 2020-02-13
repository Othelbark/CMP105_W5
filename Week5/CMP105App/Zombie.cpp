#include "Zombie.h"

Zombie::Zombie()
{
	walkingAni.addFrame(sf::IntRect(0, 0, 55, 108));
	walkingAni.addFrame(sf::IntRect(55, 0, 55, 108));
	walkingAni.addFrame(sf::IntRect(110, 0, 55, 108));
	walkingAni.addFrame(sf::IntRect(165, 0, 55, 108));
	walkingAni.addFrame(sf::IntRect(220, 0, 55, 108));
	walkingAni.addFrame(sf::IntRect(275, 0, 55, 108));
	walkingAni.addFrame(sf::IntRect(330, 0, 55, 108));
	walkingAni.addFrame(sf::IntRect(385, 0, 55, 108));
	walkingAni.setFrameSpeed(0.1f);

	setTextureRect(walkingAni.getCurrentFrame());

	isWalking = false;
	speed = 1000;
}
Zombie::~Zombie()
{
}

void Zombie::handleInput(float dt)
{
	//Find direction from input
	sf::Vector2f directionVector(0, 0);

	if (input->isKeyDown(sf::Keyboard().Left))
	{
		isWalking = true;
		walkingAni.setFlipped(true);
		directionVector.x = -1;
	}
	else if (input->isKeyDown(sf::Keyboard().Right))
	{
		isWalking = true;
		walkingAni.setFlipped(false);
		directionVector.x = 1;
	}
	else
	{
		isWalking = false;
	}

	setVelocity(directionVector * speed);
}

void Zombie::update(float dt)
{
	if (isWalking) 
	{
		//Move based on velocity
		move(velocity * dt);

		//Animate
		walkingAni.animate(dt);
		setTextureRect(walkingAni.getCurrentFrame());
	}
}
