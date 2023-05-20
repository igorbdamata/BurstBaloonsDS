#pragma once
#include<nds.h>
#include"../Engine/OamEngine.h"

class Scene
{
public:
	Scene(OamEngine* mainEngine, OamEngine* subEngine);

	virtual void Load();

	virtual void InputLoop();
	virtual void GameLoop();
	void SetMainBackgroundTo(const unsigned int* backgroundTiles, uint32 backgroundTilesLen);
	void SetSubBackgroundTo(const unsigned int* backgroundTiles, uint32 backgroundTilesLen);

private:
	OamEngine* mainEngine;
	OamEngine* subEngine;

	const unsigned int* mainBackgroundTiles;
	uint32 mainBackgroundTilesLen;

	const unsigned int* subBackgroundTiles;
	uint32 subBackgroundTilesLen;
};