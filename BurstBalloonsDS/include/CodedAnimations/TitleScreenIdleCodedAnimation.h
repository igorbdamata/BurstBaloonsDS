#pragma once
#if !defined(TITLE_SCREEN_IDLE_ANIMATION_H)
#define TITLE_SCREEN_IDLE_ANIMATION_H true

#include "../Engine/CodedAnimation.h"
#include "../Engine/Vector2.h"
#include "../Engine/Animation.h"
#include "../Engine/Entity.h"

class TitleScreenIdleCodedAnimation : public CodedAnimation
{
public:
	TitleScreenIdleCodedAnimation(Entity* pressAnyKeyText[4], Entity* burstBalloonsText[2]);
	void Update() override;
private:
	Entity* pressAnyKeyText[4];
	Entity* burstBalloonsText[2];

	void UpdateText(Entity* entities[]);
};

#endif