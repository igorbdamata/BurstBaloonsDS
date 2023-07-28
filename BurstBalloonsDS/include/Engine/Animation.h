#if !defined(ANIMATION_H)
#define ANIMATION_H 1
#pragma once

#include <nds.h>
#include "Entity.h"
#include<vector>
#include <functional>

class Animation
{
public:
	Animation(float framesInterval, int framesCount, std::function<void(void* newSprite)> setSpriteAddressTo, bool haveLoop, std::vector<void*> frames);

	void Start();
	void Update();

	bool IsPlaying();

private:
	bool isPlaying;
	bool haveLoop;

	int currentFrame;
	int framesCount;

	float framesInterval;
	float lastFrameChangeTime;

	bool finishedExecution;
	std::vector<void*> frames;
	std::function<void(void* newSprite)> setSpriteAddressTo;

	bool IsTimeToChangeFrame();
	void ChangeFrame();
	void ResetCurrentFrame();
	void FinishAnimation();
	void ChangeSpriteOnEntity();
};

#endif