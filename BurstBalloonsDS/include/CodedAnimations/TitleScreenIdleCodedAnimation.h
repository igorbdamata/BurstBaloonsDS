#pragma once
#include "../Engine/CodedAnimation.h"
#include "../Engine/Vector2.h"
#include "../Engine/Animation.h"
#include "../Engine/Entity.h"

class TitleScreenIdleCodedAnimation : public CodedAnimation
{
public:
	TitleScreenIdleCodedAnimation(Entity* pressAnyKeyText[4], Entity* burstBalloonsText[2]);
	void Start() override;
	void Update() override;
private:
	Entity* pressAnyKeyText[4];
	Entity* burstBalloonsText[2];
	void UpdatePressAnyKey();
	void UpdateBurstBalloonsText();
};