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
	void Update() override;
private:
	std::vector<Entity*> titleText;
	std::vector<Entity*> pressAnyKeyText;
	void UpdateText(std::vector<Entity*> text);
};

#endif