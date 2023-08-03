#if !defined(ANIMATION_H)
#define ANIMATION_H true
#pragma once

#include<nds.h>
#include<vector>
#include<functional>
#include "Entity.h"

class Animation
{
public:
	Animation(float intervalBetweenFrames, int framesCount, bool haveLoop, std::vector<void*> frames, std::function<void(void* newSprite)> setSpriteTo);

	void Start();
	void Update();
	bool HaveFinishedExecution();
private:
	int currentFrame;
	int framesCount;

	float intervalBetweenFrames;
	float lastFrameChangeTime;

	bool haveLoop;

	std::function<void(void* newSprite)> setSpriteTo;
	std::vector<void*> frames;

	bool haveFinishedExecution;

	bool IsTimeToChangeFrame();

	void ChangeCurrentFrame();
	void ResetCurrentFrame();
	void FinishAnimation();
};
#endif