#include "CodedAnimations/MenuIdleCodedAnimation.h"
#include "Engine/HardwareManager.h"
#include "Engine/Math.h"
#include<cmath>

MenuIdleCodedAnimation::MenuIdleCodedAnimation(std::vector<Entity*> titleText, std::vector<Entity*> pressAnyKeyText)
{
	this->titleText = titleText;
	this->pressAnyKeyText = pressAnyKeyText;
}

void MenuIdleCodedAnimation::Update()
{
	UpdateText(pressAnyKeyText);
	UpdateText(titleText);
}
void MenuIdleCodedAnimation::UpdateText(std::vector<Entity*> text)
{
	const float MOVEMENT_FREQUENCY = 1.0f;
	const float MOVEMENT_AMPLITUDE = 25.0f;
	for (int i = 0; i < text.size(); i++)
	{
		text[i]->position->y += Math::GetMovementAmountFromWaveWith(MOVEMENT_FREQUENCY, MOVEMENT_AMPLITUDE);
		text[i]->Render();
		text[i]->position->y -= Math::GetMovementAmountFromWaveWith(MOVEMENT_FREQUENCY, MOVEMENT_AMPLITUDE);
	}
}