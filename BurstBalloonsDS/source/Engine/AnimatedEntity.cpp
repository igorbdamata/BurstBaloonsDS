#include "Engine/AnimatedEntity.h"

AnimatedEntity::AnimatedEntity() : Entity() {}
AnimatedEntity::AnimatedEntity(Vector2* position, int width, int height, Vector2* spriteOffset, SpriteSize spriteSize, std::string initialAnimation)
	: Entity(position, width, height, spriteOffset, spriteSize)
{
	currentAnimation = initialAnimation;
}
AnimatedEntity::AnimatedEntity(SpriteSize spriteSize, std::string initialAnimation)
	: Entity(spriteSize)
{
	currentAnimation = initialAnimation;
}

void AnimatedEntity::AddAnimation(std::string animationName, Animation* animation)
{
	animations.insert(std::make_pair(animationName, animation));
}

void AnimatedEntity::UpdateAnimation()
{
	animations[currentAnimation]->Update();
}

std::string AnimatedEntity::GetCurrentAnimation()
{
	return currentAnimation;
}
void AnimatedEntity::ChangeAnimationTo(std::string newAnimation)
{
	currentAnimation = newAnimation;
	animations[currentAnimation]->Start();
}