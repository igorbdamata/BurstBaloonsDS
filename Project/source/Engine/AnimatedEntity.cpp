#include "Engine\AnimatedEntity.h"

AnimatedEntity::AnimatedEntity(int oamID, void *sprite, Vector2 position, OamState *engine, SpriteSize spriteSize, const char *defaultAnimation)
    : Entity(oamID, sprite, position, engine, spriteSize)
{
    currentAnimation = defaultAnimation;
}

void AnimatedEntity::AddAnimation(const char *animationName, Animation *animation)
{
    animations.insert(std::make_pair(animationName, animation));
}

void AnimatedEntity::UpdateAnimation()
{
    animations[currentAnimation]->Update();
}

void AnimatedEntity::ChangeAnimationTo(const char *newAnimation)
{
    currentAnimation = newAnimation;
    animations[currentAnimation]->Start();
}

const char *AnimatedEntity::GetCurrentAnimation()
{
    return currentAnimation;
}