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
	SplashScreenCodedAnimation(std::vector<Entity*> pressAnyKeyText,
							   GraphicsHandler* main, GraphicsHandler* sub);
	void Start() override;
	void Update() override;

private:
	GraphicsHandler* main;
	GraphicsHandler* sub;

	Animation* fadeOutAnimation;

	std::vector<Entity*> pressAnyKeyText;

	float animationStartTime;
	float fadeOutStartTime;

	bool startedFadeOut;

	void SetBackgroundTo(void* newSprite);

	void StartFadeOut();
	void UpdateFadeOut();

	void LerpPressAnyKeyText();

	void FinishSplashScreenAnimation();
};

#endif