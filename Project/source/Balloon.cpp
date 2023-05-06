#include "Balloon.h"

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

void  Balloon::Update()
{
    if(!wasBursted)
        Move();
    else if(position.y>192)
    {
        //Revert burst
    }
    ApplyGravity();
    position += velocity;
}
void Balloon::Move()
{
    velocity += moveAmount;
}
void Balloon::ApplyGravity()
{
    velocity.y += 1; 
}

void Balloon::CheckCollision(Vector2 touchPosition)
{
    if (touchPosition.x > position.x+offsetX && touchPosition.y > position.y+offsetY && touchPosition.x < position.x + width +offsetX&& touchPosition.y < position.y + height+offsetY && !wasBursted)
        OnBurst();
}

void Balloon::OnBurst()
{
    wasBursted = true;
    ChangeAnimationTo("burst");
}