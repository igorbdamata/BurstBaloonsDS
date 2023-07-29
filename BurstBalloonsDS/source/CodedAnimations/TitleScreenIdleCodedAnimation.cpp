#include "CodedAnimations/TitleScreenIdleCodedAnimation.h"
#include "Engine/HardwareManager.h"
#include<math.h>

TitleScreenIdleCodedAnimation::TitleScreenIdleCodedAnimation(Entity* pressAnyKeyText[4], Entity* burstBalloonsText[2])
{
	for (int i = 0; i < 4; i++)
	{
		this->pressAnyKeyText[i] = pressAnyKeyText[i];
	}
	for (int i = 0; i < 2; i++)
	{
		this->burstBalloonsText[i] = burstBalloonsText[i];
	}
}
void TitleScreenIdleCodedAnimation::Start()
{
}
void TitleScreenIdleCodedAnimation::Update()
{
	UpdatePressAnyKey();
	UpdateBurstBalloonsText();
}
void TitleScreenIdleCodedAnimation::UpdatePressAnyKey()
{
	for (int i = 0; i < 4; i++)
	{
		this->pressAnyKeyText[i]->position->y += sin(HardwareManager::GetCurrentMilliseconds() / 930) / 2;
		pressAnyKeyText[i]->Render();
	}
}
void TitleScreenIdleCodedAnimation::UpdateBurstBalloonsText()
{
	for (int i = 0; i < 2; i++)
	{
		this->burstBalloonsText[i]->position->y += sin((HardwareManager::GetCurrentMilliseconds()) / 930) / 2;
		burstBalloonsText[i]->Render();
	}
}