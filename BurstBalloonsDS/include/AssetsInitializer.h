#pragma once
#if !defined (ASSETS_INITIALIZER_H)
#define ASSETS_INITIALIZER_H true

#include "Engine/GraphicsHandler.h"
#include "Scenes/SceneManager.h"
#include "GameManager.h"

class AssetsInitializer
{
public:
	AssetsInitializer(GraphicsHandler* mainEngine, GraphicsHandler* subEngine, SceneManager* sceneManager, GameManager* gameManager);
	void InitializeScenes();
	void InitializeGlobalGraphics();
private:
	GraphicsHandler* mainEngine;
	GraphicsHandler* subEngine;
	SceneManager* sceneManager;
	GameManager* gameManager;

	void InitPressAnyKeyText();
};
#endif
