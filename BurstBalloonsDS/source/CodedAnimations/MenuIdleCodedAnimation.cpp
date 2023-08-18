#include "CodedAnimations/MenuIdleCodedAnimation.h"
#include "Engine/HardwareManager.h"
#include "Engine/Math.h"
#include<cmath>

MenuIdleCodedAnimation::MenuIdleCodedAnimation(std::vector<Entity*> titleText, std::vector<Entity*> pressAnyKeyText)
{
	this->titleText = titleText;
	this->pressAnyKeyText = pressAnyKeyText;
	isPlaying = false;
}

void MenuIdleCodedAnimation::Start()
{
	CodedAnimation::Start();
	animationStartTime = HardwareManager::GetCurrentSeconds();
	titleTextInitialPositionY = titleText[0]->position->y;
	pressAnyKeyTextInitialPositionY = pressAnyKeyText[0]->position->y;
}

void MenuIdleCodedAnimation::Update()
{
	UpdateText(titleText, titleTextInitialPositionY);
	UpdateText(pressAnyKeyText, pressAnyKeyTextInitialPositionY);
}
void MenuIdleCodedAnimation::UpdateText(std::vector<Entity*> text, float initialPosition)
{
	const float MOVEMENT_FREQUENCY = 1.0f;
	const float MOVEMENT_AMPLITUDE = 25.0f;
	for (int i = 0; i < text.size(); i++)
	{
		text[i]->position->y = initialPosition;
		text[i]->position->y -= Math::GetMovementAmountFromWaveWith(MOVEMENT_FREQUENCY, MOVEMENT_AMPLITUDE, -animationStartTime);
		text[i]->Render();
	}
}