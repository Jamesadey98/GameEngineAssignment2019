#pragma once
#include "errortype.h"
#include "windows.h"
#include "mydrawengine.h"
#include "gametimer.h"


class Player
{

private:
	Vector2D shipPos;
	Vector2D shipVelocity;
	Vector2D shipAcceleration;
	Vector2D friction;

	PictureIndex image;

	
	GameTimer gameTimer;

	float shipAngle;
	float frameTime;

public:

	
	void PlayerStart();
	void PlayerUpdate();
	void PlayerMovement();

};

