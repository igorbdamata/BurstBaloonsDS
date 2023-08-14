#pragma once
#if !defined(TITLE_SCREEN_IDLE_ANIMATION_H)
#define TITLE_SCREEN_IDLE_ANIMATION_H true

#include "../Engine/CodedAnimation.h"
#include "../Engine/Vector2.h"
#include "../Engine/Animation.h"
#include "../Engine/Entity.h"
#include "../Data/PressAnyKeyTextData.h"
#include "../Data/BurstBalloonsTextData.h"

class TitleScreenIdleCodedAnimation : public CodedAnimation
{
public:
	TitleScreenIdleCodedAnimation(Entity* pressAnyKeyText[PressAnyKeyTextData::TILES_LENGTH], 
								  Entity* burstBalloonsText[BurstBalloonsTextData::TILES_LENGTH]);
	void Update() override;
private:
	Entity* pressAnyKeyText[PressAnyKeyTextData::TILES_LENGTH];
	Entity* burstBalloonsText[BurstBalloonsTextData::TILES_LENGTH];

	void UpdateText(Entity* entities[], int entitiesLength);
};

#endif