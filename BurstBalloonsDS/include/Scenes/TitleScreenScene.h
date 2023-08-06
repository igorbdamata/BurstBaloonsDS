#pragma once
#include "Scene.h"
#include "../Engine/Animation.h"
#include "SceneManager.h"
#include "../GameManager.h"
#include "../CodedAnimations/SplashScreenCodedAnimation.h"
#include "../CodedAnimations/TitleScreenIdleCodedAnimation.h"

class TitleScreenScene : public Scene
{
public:
	TitleScreenScene(GraphicsHandler* mainEngine, GraphicsHandler* subEngine, SceneManager* sceneManager);

	void Load() override;

	void InputLoop() override;
	void GameLoop() override;
private:
	SceneManager* sceneManager;

	SplashScreenCodedAnimation* splashScreenCodedAnimation;
	TitleScreenIdleCodedAnimation* titleScreenIdleCodedAnimation;
};