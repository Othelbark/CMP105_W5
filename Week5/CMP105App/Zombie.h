#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Zombie :
	public GameObject
{
public:
	Zombie();
	~Zombie();

	virtual void handleInput(float dt) override;
	virtual void update(float dt) override;

	void setSpeed(float s) { speed = s; };
	float getSpeed() { return speed; };

protected:
	Animation walkingAni;
	bool isWalking;
	float speed;
};

