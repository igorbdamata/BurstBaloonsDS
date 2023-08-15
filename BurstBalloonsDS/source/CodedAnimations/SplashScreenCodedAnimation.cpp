#include "CodedAnimations/SplashScreenCodedAnimation.h"
#include "Engine/GraphicsHandler.h"
#include "Engine/HardwareManager.h"
#include "Background1.h"
#include "Data/SplashScreenData.h";
#include "Data/PressAnyKeyTextData.h";

GraphicsHandler* SplashScreenCodedAnimation::sub = NULL;
GraphicsHandler* SplashScreenCodedAnimation::main = NULL;

SplashScreenCodedAnimation::SplashScreenCodedAnimation(Entity * pressAnyKeyText[PressAnyKeyTextData::TILES_LENGTH], 
													   GraphicsHandler* main, GraphicsHandler* sub)
{
	SplashScreenCodedAnimation::sub = sub;
	SplashScreenCodedAnimation::main = main;

	for (int i = 0; i < 4; i++)
		this->pressAnyKeyText[i] = pressAnyKeyText[i];

	std::vector<void*> splashScreenFrames;
	for (int i = 0; i < SplashScreenData::FRAMES_AMOUNT; i++)
		splashScreenFrames.insert(splashScreenFrames.end(),(void*)SplashScreenData::FRAMES[i]);
	fadeOutAnimation = new Animation(SplashScreenData::INTERVAL_BETWEEN_FRAMES, SplashScreenData::FRAMES_AMOUNT, 
												 SplashScreenData::HAVE_LOOP , splashScreenFrames, 
												 [](void* newSprite) { SetBackgroundTo(newSprite); });
	startedFadeOut = false;
}
void SplashScreenCodedAnimation::SetBackgroundTo(void* newSprite)
{
	main->SetBackgroundTo(newSprite, Background1BitmapLen);
}

void SplashScreenCodedAnimation::Start()
{
	CodedAnimation::Start();
	animationStartTime = HardwareManager::GetCurrentSeconds();
}

void SplashScreenCodedAnimation::Update()
{
	bool inFadeOut = HardwareManager::GetCurrentSeconds() - animationStartTime >= SplashScreenData::SECONDS_TO_START_FADE_OUT;
	if (!inFadeOut) return;
	if (!startedFadeOut) StartFadeOut();
	UpdateFadeOut();
	if (fadeOutAnimation->HaveFinishedExecution()) FinishSplashScreenAnimation();
}
void SplashScreenCodedAnimation::StartFadeOut()
{
	fadeOutStartTime = HardwareManager::GetCurrentSeconds();
	fadeOutAnimation->Start();
	startedFadeOut = true;
}

void SplashScreenCodedAnimation::UpdateFadeOut()
{
	fadeOutAnimation->Update();
	LerpPressAnyKeyText();
}
void SplashScreenCodedAnimation::LerpPressAnyKeyText()
{
	float timeSinceFadeOutStarted = HardwareManager::GetCurrentSeconds() - fadeOutStartTime;
	const float FADE_OUT_TOTAL_TIME = SplashScreenData::INTERVAL_BETWEEN_FRAMES * SplashScreenData::FRAMES_AMOUNT;
	float fadeOutPercent = timeSinceFadeOutStarted / FADE_OUT_TOTAL_TIME;

	for (int i = 0; i < 4; i++)
	{
		this->pressAnyKeyText[i]->position->Lerp(SplashScreenData::pressAnyKeyInitialPosition, 
												 SplashScreenData::pressAnyKeyFinalPosition, 
												 fadeOutPercent);
		this->pressAnyKeyText[i]->position->x += 64 * i;
		pressAnyKeyText[i]->Render();
	}
}

void SplashScreenCodedAnimation::FinishSplashScreenAnimation()
{
	isPlaying = false;
	animationHaveFinished = true;
	main->SetBackgroundTo(Background1Bitmap, Background1BitmapLen);
}