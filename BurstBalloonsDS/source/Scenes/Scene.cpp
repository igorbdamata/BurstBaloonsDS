#include "Scenes/Scene.h"
#include "Engine/SoundManager.h"

#include <nds/arm9/input.h>

Scene::Scene(GraphicsHandler* topGraphicsHandler, GraphicsHandler* bottomGraphicsHandler)
{
	this->topGraphicsHandler = topGraphicsHandler;
	this->bottomGraphicsHandler = bottomGraphicsHandler;
}

void Scene::Load()
{
	PlotBackgroundsOnScreen();
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

void Scene::PlotBackgroundsOnScreen()
{
	topGraphicsHandler->SetBackgroundTo(mainBackgroundTiles, mainBackgroundTilesLen);
	bottomGraphicsHandler->SetBackgroundTo(subBackgroundTiles, subBackgroundTilesLen);
}