#include "CodedAnimations/TitleScreenIdleCodedAnimation.h"
#include "Engine/Math.h"

TitleScreenIdleCodedAnimation::TitleScreenIdleCodedAnimation(Entity* pressAnyKeyText[PressAnyKeyTextData::TILES_LENGTH], 
															 Entity* burstBalloonsText[BurstBalloonsTextData::TILES_LENGTH])
{
	for (int i = 0; i < PressAnyKeyTextData::TILES_LENGTH; i++)
		this->pressAnyKeyText[i] = pressAnyKeyText[i];
	for (int i = 0; i < BurstBalloonsTextData::TILES_LENGTH; i++)
		this->burstBalloonsText[i] = burstBalloonsText[i];
}

void TitleScreenIdleCodedAnimation::Update()
{
	UpdateText(pressAnyKeyText, PressAnyKeyTextData::TILES_LENGTH);
	UpdateText(burstBalloonsText, BurstBalloonsTextData::TILES_LENGTH);
}
void TitleScreenIdleCodedAnimation::UpdateText(Entity* text[], int entitiesLength)
{
	const float MOVEMENT_FREQUENCY = 1.0f;
	const float MOVEMENT_AMPLITUDE = 0.5f;
	for (int i = 0; i < entitiesLength; i++)
	{
		text[i]->position->y += Math::GetMovementAmountFromWaveWith(MOVEMENT_FREQUENCY, MOVEMENT_AMPLITUDE);
		text[i]->Render();
	}
}