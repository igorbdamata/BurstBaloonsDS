#include "CodedAnimations/SplashScreenCodedAnimation.h"
#include "Engine/HardwareManager.h"
#include "Background1.h"
#include "Engine/Vector2.h"
#include<nds/arm9/background.h>
#include "BackgroundAnimation2.h";
#include "BackgroundAnimation3.h";
#include "BackgroundAnimation4.h";
#include "BackgroundAnimation5.h";
#include "BackgroundAnimation6.h";
#include "BackgroundAnimation7.h";

SplashScreenCodedAnimation::SplashScreenCodedAnimation(Entity* pressAnyKeyText[4])
{
	for (int i = 0; i < 4; i++)
	{
		this->pressAnyKeyText[i] = pressAnyKeyText[i];
	}

	float pressAnyKeyTextPositionX = SCREEN_WIDTH / 2 - 64 * 2 + 24;
	float pressAnyKeyTextPositionY = SCREEN_HEIGHT / 2 + 80;
	pressAnyKeyInitialPosition = new Vector2(pressAnyKeyTextPositionX, pressAnyKeyTextPositionY * 2);
	pressAnyKeyFinalPosition = new Vector2(pressAnyKeyTextPositionX, pressAnyKeyTextPositionY);

	splashScreenWasFinished = false;

	std::vector<void*> splashScreenFrames;
	splashScreenFrames.insert(splashScreenFrames.end(), (void*) BackgroundAnimation3Bitmap);
	splashScreenFrames.insert(splashScreenFrames.end(), (void*) BackgroundAnimation4Bitmap);
	splashScreenFrames.insert(splashScreenFrames.end(), (void*) BackgroundAnimation5Bitmap);
	splashScreenFrames.insert(splashScreenFrames.end(), (void*) BackgroundAnimation6Bitmap);
	splashScreenFrames.insert(splashScreenFrames.end(), (void*) BackgroundAnimation7Bitmap);
	splashScreenFadeOutAnimation = new Animation(0.3f, 5, false, splashScreenFrames, [](void* newSprite) { dmaCopyHalfWords(3, newSprite, BG_BMP_RAM(1), Background1BitmapLen); });
	splashScreenFadeOutAnimation->Start();
	splashScreenSeconds = 3;
	startedSplashScreenFadeOut = false;
}

void SplashScreenCodedAnimation::Start()
{
	CodedAnimation::Start();
	splashScreenStartTime = HardwareManager::GetCurrentSeconds();
}

void SplashScreenCodedAnimation::Update()
{
	bool isTimeToStartFadeOut = HardwareManager::GetCurrentSeconds() - splashScreenStartTime >= splashScreenSeconds;
	if (!isTimeToStartFadeOut) return;
	UpdateFadeOut();
	if (splashScreenFadeOutAnimation->HaveFinishedExecution())FinishSplashScreenAnimation();
}

void SplashScreenCodedAnimation::UpdateFadeOut()
{
	if (!startedSplashScreenFadeOut) StartFadeOut();
	splashScreenFadeOutAnimation->Update();
	LerpPressAnyKeyText();
}

void SplashScreenCodedAnimation::StartFadeOut()
{
	splashScreenFadeOutStartSeconds = HardwareManager::GetCurrentSeconds();
	splashScreenFadeOutAnimation->Start();
	startedSplashScreenFadeOut = true;
}

void SplashScreenCodedAnimation::LerpPressAnyKeyText()
{
	for (int i = 0; i < 4; i++)
	{
		float timeSinceFadeOutStarted = HardwareManager::GetCurrentSeconds() - splashScreenFadeOutStartSeconds;
		float fadeOutTotalTime = 0.3f * 5;
		float fadeOutPercent = timeSinceFadeOutStarted / fadeOutTotalTime;
		this->pressAnyKeyText[i]->position->Lerp(pressAnyKeyInitialPosition, pressAnyKeyFinalPosition, fadeOutPercent);
		this->pressAnyKeyText[i]->position->x += 64 * i;
		pressAnyKeyText[i]->Render();
	}
}

void SplashScreenCodedAnimation::FinishSplashScreenAnimation()
{
	this->Stop();
	splashScreenWasFinished = true;
	dmaCopyHalfWords(3, Background1Bitmap, BG_BMP_RAM(1), Background1BitmapLen);
}


bool SplashScreenCodedAnimation::HaveFinished()
{
	return splashScreenWasFinished;
}