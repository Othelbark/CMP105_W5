#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Mario :
	public GameObject
{
public:
	Mario();
	~Mario();

	virtual void handleInput(float dt) override;
	virtual void update(float dt) override;

	void setSpeed(float s) { speed = s; };
	float getSpeed() { return speed; };

protected:
	Animation* currentAni;
	Animation walkingAni;
	Animation swimingAni;
	Animation crouchingAni;


	sf::Vector2f directionVector;
	bool isWalking;
	bool isSwiming;
	bool isCrouching;
	bool isFlipped;
	float speed;
};

