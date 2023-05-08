#include "Balloon.h"
#include <nds.h>
#include <iostream>

Balloon::Balloon(Vector2 position, SpriteSize spriteSize, const char *defaultAnimation, const void *tiles, int speed, int width, int height, int offsetX, int offsetY)
    : AnimatedEntity(position, spriteSize, defaultAnimation, tiles)
{
    this->speed = speed;
    this->width = width;
    this->height = height;
    this->offsetX = offsetX;
    this->offsetY = offsetY;
    moveAmount = Vector2(0, 0);
    velocity = Vector2(0, 0);
    Init();
}

void Balloon::Init()
{
    verticalDirection = -1;
    moveAmount.y = verticalDirection * speed;
}

void Balloon::Update()
{
    if (!wasBursted)
    {
        if (position.y + height < 0)
            RemoveLife();
        Move();
    }
    else if (position.y > SCREEN_HEIGHT)
        Respawn();
    ApplyGravity();
    position += velocity;
}
void Balloon::Move()
{
    velocity = moveAmount;
}
void Balloon::ApplyGravity()
{
    velocity.y += 0.1;
}

void Balloon::CheckCollision(Vector2 touchPosition)
{
    if (touchPosition.x > position.x + offsetX && touchPosition.y > position.y + offsetY && touchPosition.x < position.x + width + offsetX && touchPosition.y < position.y + height + offsetY && !wasBursted)
        OnBurst();
}

void Balloon::OnBurst()
{
    wasBursted = true;
    ChangeAnimationTo("burst");
}

void Balloon::Respawn()
{
    wasBursted = false;
    ChangeAnimationTo("fly");
    int randomPositionX = rand() % (SCREEN_WIDTH - width*2);
    position.x = randomPositionX;
    position.y = SCREEN_HEIGHT - height;
}

void Balloon::RemoveLife()
{
    Respawn();
}