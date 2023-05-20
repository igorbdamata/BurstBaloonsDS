#include "Scenes\Scene.h"
#include <nds/arm9/input.h>

Scene::Scene(OamEngine* mainEngine, OamEngine* subEngine)
{
	this->mainEngine = mainEngine;
	this->subEngine = subEngine;
}

void Scene::Load()
{
	mainEngine->SetBackgroundTo(mainBackgroundTiles, mainBackgroundTilesLen);
	subEngine->SetBackgroundTo(subBackgroundTiles, subBackgroundTilesLen);
}

void Scene::InputLoop() 
{
	scanKeys();
}
void Scene::GameLoop() {}

void Scene::SetMainBackgroundTo(const unsigned int* backgroundTiles, uint32 backgroundTilesLen)
{
	mainBackgroundTiles = backgroundTiles;
	mainBackgroundTilesLen = backgroundTilesLen;
}
void Scene::SetSubBackgroundTo(const unsigned int* backgroundTiles, uint32 backgroundTilesLen)
{
	subBackgroundTiles = backgroundTiles;
	subBackgroundTilesLen = backgroundTilesLen;
}