#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "../CodedAnimations/SplashScreenCodedAnimation.h"
#include "../CodedAnimations/MenuIdleCodedAnimation.h"

class TitleScreenScene : public Scene
{
public:
	TitleScreenScene(GraphicsHandler* topGraphicsHandler, GraphicsHandler* bottomGraphicsHandler, SceneManager* sceneManager);

	void Load() override;

	void InputLoop() override;
	void GameLoop() override;
private:
	SceneManager* sceneManager;

	SplashScreenCodedAnimation* splashScreenCodedAnimation;
	MenuIdleCodedAnimation* idleCodedAnimation;
};