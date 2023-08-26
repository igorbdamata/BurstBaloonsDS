#pragma once
#include<nds.h>
#include"../Engine/GraphicsHandler.h"

class Scene
{
public:
	Scene(GraphicsHandler* topGraphicsHandler, GraphicsHandler* bottomGraphicsHandler);

	virtual void Load();

	virtual void InputLoop();
	virtual void GameLoop();

	void SetMainBackgroundTo(const void* backgroundTiles, uint32 backgroundTilesLen);
	void SetSubBackgroundTo(const void* backgroundTiles, uint32 backgroundTilesLen);
	void PlotBackgroundsOnScreen();
protected:
	GraphicsHandler* topGraphicsHandler;
	GraphicsHandler* bottomGraphicsHandler;
private:
	void* mainBackgroundTiles;
	uint32 mainBackgroundTilesLen;

	void* subBackgroundTiles;
	uint32 subBackgroundTilesLen;
};