#include "Balloon.h"
#include "Data.h"
#include "Data/BalloonData.h"
#include "Engine/SoundManager.h"
#include <soundbank.h>
#include <nds.h>
#include <iostream>
#include <string>

Balloon::Balloon(GameManager* gameManager) : AnimatedEntity(BalloonData::SPRITE_SIZE, BalloonData::INITIAL_ANIMATION)
{
	speed = 0;
	speedOnMaxDifficult = BalloonData::SPEED_ON_MAX_DIFFICULT;
	this->gameManager = gameManager;

	velocity = new Vector2(0, 0);
	position = new Vector2(0, 0);
	wasBursted = false;

	Vector2* colliderOffset = new Vector2(BalloonData::COLLIDER_OFFSET_X, BalloonData::COLLIDER_OFFSET_Y);
	colliderRect = new Rect(this->position, colliderOffset, BalloonData::COLLIDER_WIDTH, BalloonData::COLLIDER_HEIGHT);

	delete spriteRect;
	Vector2* spriteOffset = new Vector2(BalloonData::SPRITE_OFFSET_X, BalloonData::SPRITE_OFFSET_Y);
	spriteRect = new Rect(this->position, spriteOffset, BalloonData::SPRITE_WIDTH, BalloonData::SPRITE_HEIGHT);

	SetPositionToRandomPoint();
}

void Balloon::Update()
{
	if (!wasBursted)
	{
		if (position->y + BALLOON_SPRITE_HEIGHT < 0)
			RemoveLife();
		else
			MoveUpwards();
	}
	else if (colliderRect->GetTopEdge() > SCREEN_HEIGHT)
		Respawn();
	velocity->y += GRAVITY_FORCE;
	ApplyVelocity();
}
void Balloon::ApplyVelocity()
{
	*position += *velocity;
}
void Balloon::MoveUpwards()
{
	speed = gameManager->GetDifficultFactor() * speedOnMaxDifficult;
	velocity->y = UP_DIRECTION * speed;
}

bool Balloon::IsCollidingWith(Vector2* point)
{
	return colliderRect->IsCollidingWith(point);
}

void Balloon::Burst()
{
	if (wasBursted) return;
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
	position->x = RandomInRange(colliderRect->GetUnpositionedLeftEdge(), SCREEN_WIDTH - colliderRect->GetUnpositionedRightEdge());
	position->y = RandomInRange(colliderRect->GetUnpositionedTopEdge(), colliderRect->GetUnpositionedBottomEdge());
	position->y += SCREEN_HEIGHT;
}
int Balloon::RandomInRange(int lowestInclusiveValue, int highestExclusiveValue)
{
	return lowestInclusiveValue + rand() % (highestExclusiveValue - lowestInclusiveValue);
}

void Balloon::RemoveLife()
{
	gameManager->RemoveLife();
	Respawn();
}