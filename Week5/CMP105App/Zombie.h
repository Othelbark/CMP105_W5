#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Zombie :
	public GameObject
{
public:
	Zombie();
	~Zombie();

	virtual void update(float dt) override;

private:
	Animation walkingAni;
};

