#pragma once
#include "Player.h"
#include "mydrawengine.h"
#include "mysoundengine.h"
#include "myinputs.h"
#include <time.h>
#include "gametimer.h"
#include "errorlogger.h"
#include <math.h>
#include "shapes.h"


void Player::PlayerStart()
{
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
	image = pDE->LoadPicture(L"./assets/harrasser.bmp");
	shipPos = Vector2D(0, 0); //initialise the ships starting position
	shipVelocity.setBearing(1.2f, 40.0f);
}

void Player::PlayerMovement()
{

	MyInputs* pInputs = MyInputs::GetInstance();
	pInputs->SampleKeyboard();

	if (pInputs->KeyPressed(DIK_W)) //if W is pressed move up
	{
		shipPos = shipPos + Vector2D(0, 4.0f);
		//shipVelocity.setBearing(0, 4.0f);

	}

	if (pInputs->KeyPressed(DIK_D)) //If D is pressed move right
	{
		shipPos = shipPos + Vector2D(4.0f, 0);
		//shipVelocity.setBearing(0, 4.0f);

	}

	if (pInputs->KeyPressed(DIK_A)) //If A is pressed move left
	{
		shipPos = shipPos + Vector2D(-4.0f, 0);
	}

	if (pInputs->KeyPressed(DIK_S)) //If S id pressed move down 
	{
		shipPos = shipPos + Vector2D(0, -4.0f);
	}
}

void Player::PlayerUpdate()
{
	MyDrawEngine* pDE = MyDrawEngine::GetInstance(); //gets the pointer to the draw engine
	pDE->DrawAt(shipPos, image, 0.5f, 0, 0.8f); //draws the image of the spaceship


}
