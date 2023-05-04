#if !defined(ANIMATED_ENTITY_H)
#define ANIMATED_ENTITY_H 1
#pragma once
 
#include "Entity.h"
#include "Animation.h"
#include <map>

class AnimatedEntity : public Entity
{
public:
    AnimatedEntity(int oamID, void* sprite, Vector2 position, OamState* engine, SpriteSize spriteSize, const char* defaultAnimation);
    void AddAnimation(const char* animationName, Animation* animation);
    void UpdateAnimation();
    void ChangeAnimationTo(const char* newAnimation);
    const char* GetCurrentAnimation();
private:
    std::map<const char *, Animation*> animations;
    const char* currentAnimation;
};

#endif