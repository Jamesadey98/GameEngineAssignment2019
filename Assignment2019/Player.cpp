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
	
	shipAcceleration.set(0,0);
	shipVelocity.set(0, 0);
}

void Player::PlayerMovement()
{

	MyInputs* pInputs = MyInputs::GetInstance();
	pInputs->SampleKeyboard();

	if (pInputs->KeyPressed(DIK_W)) //if W is pressed move up
	{
		shipVelocity.setBearing(shipAngle, 4.0f);
		shipPos = shipPos + shipVelocity;

	}

	if (pInputs->KeyPressed(DIK_D)) //If D is pressed move right
	{
		shipAngle = shipAngle +  0.1f;
		friction = -1 * shipVelocity;
		shipPos = shipPos + shipVelocity * frameTime;
		
	}

	if (pInputs->KeyPressed(DIK_A)) //If A is pressed move left
	{
		shipAngle = shipAngle + -0.1f;
	}

	if (pInputs->KeyPressed(DIK_S)) //If S id pressed move down 
	{
		//TO DO: MAKE THIS USE THRUSTERS TO INCREASE SPEED
	}
}

void Player::PlayerUpdate()
{
	gameTimer.mark();
	frameTime = gameTimer.mdFrameTime;

	MyDrawEngine* pDE = MyDrawEngine::GetInstance(); //gets the pointer to the draw engine
	pDE->DrawAt(shipPos, image, 0.5f, shipAngle, 0.8f); //draws the image of the spaceship
	pDE->WriteDouble(Vector2D(100, 100), frameTime, pDE->CYAN); //draw debug 
	


}