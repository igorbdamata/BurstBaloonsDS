#include "Balloon.h"

Balloon::Balloon(Vector2 position, SpriteSize spriteSize, const char *defaultAnimation, const void *tiles)
    : AnimatedEntity(position, spriteSize, defaultAnimation, tiles)
{
}