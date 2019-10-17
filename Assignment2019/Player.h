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
	PictureIndex image;

public:


	void PlayerStart();
	void PlayerUpdate();
	void PlayerMovement();

};

