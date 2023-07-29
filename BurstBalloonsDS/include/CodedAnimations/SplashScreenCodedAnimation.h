#pragma once
#include "../Engine/CodedAnimation.h"
#include "../Engine/Vector2.h"
#include "../Engine/Animation.h"

class SplashScreenCodedAnimation : public CodedAnimation
{
public:
	SplashScreenCodedAnimation(Entity* pressAnyKeyText[4]);
	void Start() override;
	void Update() override;
	bool HaveFinished() override;
private:
	Entity* pressAnyKeyText[4];
	bool splashScreenWasFinished;
	float splashScreenStartTime;
	float splashScreenSeconds = 3;
	bool startedSplashScreenFadeOut;
	Animation* splashScreenFadeOutAnimation;
	Vector2* pressAnyKeyInitialPosition;
	Vector2* pressAnyKeyFinalPosition;
	float splashScreenFadeOutStartSeconds;

	void UpdateFadeOut();
	void StartFadeOut();
	void LerpPressAnyKeyText();
	void FinishSplashScreenAnimation();
};