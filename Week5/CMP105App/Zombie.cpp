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
}
Zombie::~Zombie()
{
}

void Zombie::update(float dt)
{
	walkingAni.animate(dt);
	setTextureRect(walkingAni.getCurrentFrame());
}
