#include <nds.h>
#include <string>

#include <soundbank.h>

#include "Balloon.h"

#include "Engine/SoundManager.h"
#include "Engine/Math.h"

#include "Data/BalloonData.h"
#include "Data/FlyAnimationData.h"
#include "Data/BurstAnimationData.h"

#include "Data/GameplayData.h"
#include "Data/HardwareData.h"

Balloon::Balloon(GameManager* gameManager, std::vector<void*> flyAnimationFrames, std::vector<void*> burstAnimationFrames) 
	: AnimatedEntity(BalloonData::SPRITE_SIZE, BalloonData::INITIAL_ANIMATION)
{
	this->gameManager = gameManager;

	velocity = new Vector2(0, 0);
	position = new Vector2(0, 0);
	wasBursted = false;

	Vector2* colliderOffset = new Vector2(BalloonData::COLLIDER_OFFSET_X, BalloonData::COLLIDER_OFFSET_Y);
	colliderRect = new Rect(this->position, colliderOffset, BalloonData::COLLIDER_WIDTH, BalloonData::COLLIDER_HEIGHT);

	delete spriteRect;
	Vector2* spriteOffset = new Vector2(BalloonData::SPRITE_OFFSET_X, BalloonData::SPRITE_OFFSET_Y);
	spriteRect = new Rect(this->position, spriteOffset, BalloonData::SPRITE_WIDTH, BalloonData::SPRITE_HEIGHT);

	Animation* flyAnimation = new Animation(FlyAnimationData::INTERVAL_BETWEEN_FRAMES,
											FlyAnimationData::FRAMES_COUNT,
											FlyAnimationData::HAS_LOOP,
											flyAnimationFrames, 
											[this](void* newSprite) {SetSpriteTo(newSprite); });
	Animation* burstAnimation = new Animation(BurstAnimationData::INTERVAL_BETWEEN_FRAMES,
											  BurstAnimationData::FRAMES_COUNT,
											  BurstAnimationData::HAS_LOOP,
											  burstAnimationFrames, 
											  [this](void* newSprite) {SetSpriteTo(newSprite); });
	AddAnimation("fly", flyAnimation);
	AddAnimation("burst", burstAnimation);

	SetPositionToRandomPoint();
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

void Balloon::Update()
{
	if (!wasBursted) BalloonIdleUpdate();
	else BalloonBurstedUpdate();

	ApplyPhysics();

	Render();
	UpdateAnimation();
}

void Balloon::BalloonIdleUpdate()
{
	MoveUpwards();
	if (spriteRect->IsAbove(HardwareData::screenRect))
		OnGetAboveScreen();
}
void Balloon::MoveUpwards()
{
	const int UP_DIRECTION = -1;
	float speed = gameManager->GetDifficultFactor() * BalloonData::SPEED_ON_MAX_DIFFICULT;
	velocity->y = UP_DIRECTION * speed;
}
void Balloon::OnGetAboveScreen()
{
	gameManager->RemoveLife();
	Respawn();
}

void Balloon::BalloonBurstedUpdate()
{
	if (spriteRect->IsBelow(HardwareData::screenRect))
		Respawn();
}

void Balloon::ApplyPhysics()
{
	velocity->y += GameplayData::GRAVITY_FORCE;
	*position += *velocity;
}

void Balloon::Respawn()
{
	wasBursted = false;
	ChangeAnimationTo("fly");
	SetPositionToRandomPoint();
}

void Balloon::SetPositionToRandomPoint()
{
	float maxPositionX = HardwareData::screenRect->GetRightEdge() - colliderRect->GetUnpositionedRightEdge();
	position->x = Math::RandomInRange(colliderRect->GetUnpositionedLeftEdge(), maxPositionX);

	position->y = HardwareData::screenRect->GetBottomEdge() + colliderRect->GetUnpositionedTopEdge();
	position->y += Math::RandomInRange(0, BalloonData::POSITION_Y_VARIATION_ON_SPAWN);
}