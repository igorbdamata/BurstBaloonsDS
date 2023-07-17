#pragma once
#include "AnimatedEntity.h"
#include "GameManager.h"

class Balloon : public AnimatedEntity
{
public:
    Balloon();
    Balloon(SpriteSize spriteSize, const char *defaultAnimation,float maxSpeed, int width, int height, int offsetX, int offsetY, GameManager *gameManager);
    void Update();
    void CheckCollision(Vector2* touchPosition);
    void Respawn();
private:
    float verticalDirection;
    float speed;
    float maxSpeed;
    int offsetX;
    int offsetY;
    Vector2* moveAmount;
    Vector2* velocity;

    GameManager *gameManager;

    bool wasBursted;

    void Init();
    void Move();
    void ApplyGravity();
    void OnBurst();
    void RemoveLife();
    void SetPositionToRandomPoint();
};