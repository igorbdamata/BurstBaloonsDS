#include "Engine/Animation.h"
#include "Engine/HardwareManager.h"
#include<string>

Animation::Animation(float framesInterval, int framesCount, std::function<void(void* newSprite)> setSpriteAddressTo, bool haveLoop, std::vector<void*> frames)
{
	this->framesInterval = framesInterval;
	this->framesCount = framesCount;
	this->setSpriteAddressTo = setSpriteAddressTo;
	this->haveLoop = haveLoop;
	this->frames = frames;
	this->finishedExecution = false;
}

bool Animation::IsPlaying()
{
	return isPlaying;
}

void Animation::Start()
{
	currentFrame = 0;
	finishedExecution = false;
}

void Animation::Update()
{
	if (!IsTimeToChangeFrame() || (!haveLoop && finishedExecution))
		return;

	ChangeFrame();
	ChangeSpriteOnEntity();
}
bool Animation::IsTimeToChangeFrame()
{
	float currentTime = HardwareManager::GetCurrentMilliseconds() / 1000;
	return currentTime - lastFrameChangeTime >= framesInterval;
}

void Animation::ChangeFrame()
{
	currentFrame++;
	lastFrameChangeTime = HardwareManager::GetCurrentMilliseconds() / 1000;
	if (currentFrame < framesCount)
		return;
	ResetCurrentFrame();
}
void Animation::ResetCurrentFrame()
{
	if (haveLoop)
	{
		currentFrame = 0;
		return;
	}
	FinishAnimation();
}
void Animation::FinishAnimation()
{
	finishedExecution = true;
	currentFrame = framesCount - 1;
}

void Animation::ChangeSpriteOnEntity()
{
	setSpriteAddressTo(frames[currentFrame]);
}