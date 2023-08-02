#pragma once
#include "Engine/Rect.h"
#include "Engine/AnimatedEntity.h"
#include "GameManager.h"

class Balloon : public AnimatedEntity
{
public:
	Balloon(GameManager* gameManager);
	
	bool IsCollidingWith(Vector2* touchPosition);

	void Update();
	
	void Burst();
	void Respawn();

private:
	GameManager* gameManager;
	
	Rect* colliderRect;
	Vector2* velocity;

	bool wasBursted;

	void BalloonIdleUpdate();
	void MoveUpwards();
	void OnGetAboveScreen();

	void BalloonBurstedUpdate();

	void ApplyPhysics();

	void SetPositionToRandomPoint();
};