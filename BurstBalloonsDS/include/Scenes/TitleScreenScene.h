#pragma once
#include "Scene.h"
#include "../Engine/Animation.h"
#include "SceneManager.h"
#include "../GameManager.h"

class TitleScreenScene : public Scene
{
public:
	TitleScreenScene(OamEngine* mainEngine, OamEngine* subEngine, SceneManager* sceneManager);

	void Load() override;

	void InputLoop() override;
	void GameLoop() override;
private:
	SceneManager* sceneManager;
	Entity* pressAnyKeyText[4];
	Entity* burstBalloonsText[2];

	bool splashScreenWasFinished;
	float splashScreenStartTime;
	float splashScreenSeconds = 3;
	bool startedSplashScreenFadeOut;
	void UpdateSplashScreen();
	Animation* splashScreenFadeOutAnimation;
	Vector2* pressAnyKeyInitialPosition;
	Vector2* pressAnyKeyFinalPosition;
	float splashScreenFadeOutStartSeconds;

	void UpdateFadeOut();
	void StartFadeOut();
	void LerpPressAnyKeyText();
	void FinishSplashScreenAnimation();

	void UpdatePressAnyKey();
	void UpdateBurstBalloonsText();
};