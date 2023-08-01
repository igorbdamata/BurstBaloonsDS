#pragma once
#include "Engine/Rect.h"
#include "Engine/AnimatedEntity.h"
#include "GameManager.h"

class Balloon : public AnimatedEntity
{
public:
	Balloon(GameManager* gameManager);
	void Update();
	bool IsCollidingWith(Vector2* touchPosition);
	void Respawn();
	void Burst();
private:
	Rect* colliderRect;
	float speed;
	float speedOnMaxDifficult;
	Vector2* velocity;

	GameManager* gameManager;

	bool wasBursted;

	void Init();
	void ApplyVelocity();
	void MoveUpwards();
	void RemoveLife();
	void SetPositionToRandomPoint();

	int  RandomInRange(int lowestInclusiveValue, int highestExclusiveValue);
};