#pragma once
#if !defined(ANIMATED_ENTITY_H)
#define ANIMATED_ENTITY_H true

#include <map>
#include <string>

#include "Entity.h"
#include "Animation.h"

class AnimatedEntity : public Entity
{
public:
	AnimatedEntity();
	AnimatedEntity(SpriteSize spriteSize, std::string initialAnimation);
	AnimatedEntity(Vector2* position, int width, int height, Vector2* spriteOffset, SpriteSize spriteSize, std::string initialAnimation);

	void AddAnimation(std::string animationName, Animation* animation);

	void UpdateAnimation();

	std::string GetCurrentAnimation();
	void ChangeAnimationTo(std::string newAnimation);

private:
	std::map<std::string, Animation*> animations;
	std::string currentAnimation;
};

#endif