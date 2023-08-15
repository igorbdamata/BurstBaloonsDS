#if !defined(ANIMATION_H)
#define ANIMATION_H true
#pragma once

#include<nds.h>
#include<vector>
#include<functional>

class Animation
{
public:
	Animation(float intervalBetweenFrames, int framesAmount, bool haveLoop, std::vector<void*> frames, std::function<void(void* newSprite)> setSpriteTo);

	void Start();
	void Update();
	bool HaveFinishedExecution();
private:
	int currentFrame;
	int framesAmount;

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