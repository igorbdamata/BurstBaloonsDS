#pragma once
#if !defined(SPLASH_SCREEN_CODED_ANIMATION_H)
#define SPLASH_SCREEN_CODED_ANIMATION_H true

#include "../Engine/Entity.h"
#include "../Engine/GraphicsHandler.h"
#include "../Engine/CodedAnimation.h"
#include "../Engine/Vector2.h"
#include "../Engine/Animation.h"
#include "../Data/PressAnyKeyTextData.h";

class SplashScreenCodedAnimation : public CodedAnimation
{
public:
	SplashScreenCodedAnimation(Entity* pressAnyKeyText[PressAnyKeyTextData::TILES_LENGTH], 
							   GraphicsHandler* main, GraphicsHandler* sub);
	void Start() override;
	void Update() override;

private:
	static GraphicsHandler* main;
	static GraphicsHandler* sub;

	Animation* fadeOutAnimation;

	Entity* pressAnyKeyText[PressAnyKeyTextData::TILES_LENGTH];

	float animationStartTime;
	float fadeOutStartTime;
	
	bool startedFadeOut;

	static void SetBackgroundTo(void* newSprite);

	void StartFadeOut();
	void UpdateFadeOut();

	void LerpPressAnyKeyText();

	void FinishSplashScreenAnimation();
};

#endif