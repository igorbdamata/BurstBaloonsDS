#pragma once
#include "AnimatedEntity.h"

class Balloon : public AnimatedEntity
{
public:
    Balloon(Vector2 position, SpriteSize spriteSize, const char *defaultAnimation, const void *tiles, int speed, int width, int height, int offsetX, int offsetY);
    void Update();
    void CheckCollision(Vector2 touchPosition);

private:
    int verticalDirection;
    int speed;
    int width;
    int height;
    int offsetX;
    int offsetY;
    Vector2 moveAmount;
    Vector2 velocity;

    bool wasBursted;

    void Init();
    void Move();
    void ApplyGravity();
    void OnBurst();
};