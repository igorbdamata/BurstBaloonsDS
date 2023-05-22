#include "Balloon.h"
#include "Engine/SoundManager.h"
#include <soundbank.h>
#include <soundbank_bin.h>
#include <nds.h>
#include <iostream>

Balloon::Balloon() : AnimatedEntity() {}
Balloon::Balloon(SpriteSize spriteSize, const char* defaultAnimation, int speed, int width, int height, int offsetX, int offsetY, GameManager* gameManager)
	: AnimatedEntity(nullptr, spriteSize, defaultAnimation, width, height)
{
	this->speed = speed;
	this->offsetX = offsetX;
	this->offsetY = offsetY;
	this->gameManager = gameManager;
	moveAmount = new Vector2(0, 0);
	velocity = new Vector2(0, 0);
	position = new Vector2(0, 0);
	wasBursted = false;
	Init();
	SetPositionToRandomPoint();
}

void Balloon::Init()
{
	verticalDirection = -1;
	moveAmount->y = verticalDirection * speed;
}

void Balloon::Update()
{
	if (!wasBursted)
	{
		if (position->y + 64 < 0)
			RemoveLife();
		Move();
	}
	else if (position->y > SCREEN_HEIGHT)
		Respawn();
	ApplyGravity();
	*position += *velocity;
}
void Balloon::Move()
{
	*velocity = *moveAmount;
}
void Balloon::ApplyGravity()
{
	velocity->y += 0.1;
}

void Balloon::CheckCollision(Vector2* touchPosition)
{
	if (touchPosition->x > position->x + offsetX && touchPosition->y > position->y + offsetY && touchPosition->x < position->x + width + offsetX && touchPosition->y < position->y + height + offsetY && !wasBursted)
		OnBurst();
}

void Balloon::OnBurst()
{
	wasBursted = true;
	SoundManager::PlaySFX(SFX_BURSTBALLOON);
	ChangeAnimationTo("burst");
	gameManager->AddToScore(1);
}

void Balloon::Respawn()
{
	wasBursted = false;
	ChangeAnimationTo("fly");
	SetPositionToRandomPoint();
}

void Balloon::SetPositionToRandomPoint()
{
	int randomPositionX = rand() % (SCREEN_WIDTH - width * 2);
	int randomPositionY = SCREEN_HEIGHT + rand() % 100;
	position->x = randomPositionX;
	position->y = randomPositionY;
}

void Balloon::RemoveLife()
{
	gameManager->RemoveLife();
	Respawn();
}