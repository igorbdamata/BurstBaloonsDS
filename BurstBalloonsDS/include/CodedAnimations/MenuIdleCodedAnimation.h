#pragma once
#if !defined(TITLE_SCREEN_IDLE_ANIMATION_H)
#define TITLE_SCREEN_IDLE_ANIMATION_H true

#include <vector>

#include "../Engine/CodedAnimation.h"
#include "../Engine/Vector2.h"
#include "../Engine/Animation.h"
#include "../Engine/Entity.h"

class MenuIdleCodedAnimation : public CodedAnimation
{
public:
	MenuIdleCodedAnimation(std::vector<Entity*> titleText, std::vector<Entity*> pressAnyKeyText);
	void Start() override;
	void Update() override;
private:
	std::vector<Entity*> titleText;
	std::vector<Entity*> pressAnyKeyText;

	float animationStartTime;
	float titleTextInitialPositionY;
	float pressAnyKeyTextInitialPositionY;

	void UpdateText(std::vector<Entity*> text, float initialPosition);
};

#endif