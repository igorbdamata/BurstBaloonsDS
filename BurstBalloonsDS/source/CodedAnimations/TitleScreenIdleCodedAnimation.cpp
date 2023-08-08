#include "CodedAnimations/TitleScreenIdleCodedAnimation.h"
#include "Engine/Math.h"

TitleScreenIdleCodedAnimation::TitleScreenIdleCodedAnimation(Entity* pressAnyKeyText[4], Entity* burstBalloonsText[2])
{
	for (int i = 0; i < 4; i++)
		this->pressAnyKeyText[i] = pressAnyKeyText[i];
	for (int i = 0; i < 2; i++)
		this->burstBalloonsText[i] = burstBalloonsText[i];
}

void TitleScreenIdleCodedAnimation::Update()
{
	UpdateText(pressAnyKeyText);
	UpdateText(burstBalloonsText);
}
void TitleScreenIdleCodedAnimation::UpdateText(Entity* text[])
{
	const float MOVEMENT_FREQUENCY = 1.0f;
	const float MOVEMENT_AMPLITUDE = 0.5f;
	int entitiesLength = sizeof(text) / sizeof(Entity*);
	for (int i = 0; i < 4; i++)
	{
		text[i]->position->y += Math::GetMovementAmountFromWaveWith(MOVEMENT_FREQUENCY, MOVEMENT_AMPLITUDE);
		text[i]->Render();
	}
}