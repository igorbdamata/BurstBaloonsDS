#include "Engine/AnimatedEntity.h"

AnimatedEntity::AnimatedEntity() : Entity() {}
AnimatedEntity::AnimatedEntity(Vector2* position, SpriteSize spriteSize, const char* defaultAnimation, int width, int height)
	: Entity(position, spriteSize, width, height)
{
	currentAnimation = defaultAnimation;
}

void AnimatedEntity::AddAnimation(const char* animationName, Animation* animation)
{
	animations.insert(std::make_pair(animationName, animation));
}

void AnimatedEntity::UpdateAnimation()
{
	animations[currentAnimation]->Update();
}

void AnimatedEntity::ChangeAnimationTo(const char* newAnimation)
{
	currentAnimation = newAnimation;
	animations[currentAnimation]->Start();
}

const char* AnimatedEntity::GetCurrentAnimation()
{
	return currentAnimation;
}