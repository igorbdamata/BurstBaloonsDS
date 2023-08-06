#pragma once
#include<nds.h>
#include"../Engine/GraphicsHandler.h"

class Scene
{
public:
	Scene(GraphicsHandler* mainEngine, GraphicsHandler* subEngine);

	virtual void Load();

	virtual void InputLoop();
	virtual void GameLoop();
	void SetMainBackgroundTo(const void* backgroundTiles, uint32 backgroundTilesLen);
	void SetSubBackgroundTo(const void* backgroundTiles, uint32 backgroundTilesLen);

protected:
	GraphicsHandler* mainEngine;
	GraphicsHandler* subEngine;
private:
	void* mainBackgroundTiles;
	uint32 mainBackgroundTilesLen;

	void* subBackgroundTiles;
	uint32 subBackgroundTilesLen;
};