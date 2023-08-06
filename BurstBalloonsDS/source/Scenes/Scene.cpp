#include "Scenes/Scene.h"
#include <nds/arm9/input.h>
#include "font.h"
#include "Engine/SoundManager.h"

Scene::Scene(GraphicsHandler* mainEngine, GraphicsHandler* subEngine)
{
	this->mainEngine = mainEngine;
	this->subEngine = subEngine;
}

void Scene::Load()
{
	mainEngine->SetBackgroundTo(mainBackgroundTiles, mainBackgroundTilesLen);
	subEngine->SetBackgroundTo(subBackgroundTiles, subBackgroundTilesLen);
	subEngine->SetTextFontTo((void*) fontTiles, (void*) fontPal, fontPalLen);
	SoundManager::StopAllSFXs();
}

void Scene::InputLoop() 
{
	scanKeys();
}
void Scene::GameLoop() {}

void Scene::SetMainBackgroundTo(const void* backgroundTiles, uint32 backgroundTilesLen)
{
	mainBackgroundTiles = (void*)backgroundTiles;
	mainBackgroundTilesLen = backgroundTilesLen;
}
void Scene::SetSubBackgroundTo(const void* backgroundTiles, uint32 backgroundTilesLen)
{
	subBackgroundTiles = (void*)backgroundTiles;
	subBackgroundTilesLen = backgroundTilesLen;
}