#if !defined(ANIMATED_ENTITY_H)
#define ANIMATED_ENTITY_H 1
#pragma once

#include "Entity.h"
#include "Animation.h"
#include <map>

class AnimatedEntity : public Entity
{
public:
    AnimatedEntity();  
    AnimatedEntity(Vector2 position, SpriteSize spriteSize, const char *defaultAnimation, const void *tiles);
    void AddAnimation(const char *animationName, Animation *animation);
    void UpdateAnimation();
    void ChangeAnimationTo(const char *newAnimation);
    const char *GetCurrentAnimation();

private:
    std::map<const char *, Animation *> animations;
    const char *currentAnimation;
};

#endif