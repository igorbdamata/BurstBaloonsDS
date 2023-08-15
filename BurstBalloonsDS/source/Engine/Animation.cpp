#include<string>

#include "Engine/Animation.h"
#include "Engine/HardwareManager.h"

Animation::Animation(float intervalBetweenFrames, int framesAmount, bool haveLoop, std::vector<void*> frames, std::function<void(void* newSprite)> setSpriteTo)
{
	this->intervalBetweenFrames = intervalBetweenFrames;
	this->framesAmount = framesAmount;
	this->haveLoop = haveLoop;
	this->frames = frames;
	this->setSpriteTo = setSpriteTo;
	this->haveFinishedExecution = false;
}

void Animation::Start()
{
	currentFrame = 0;
	haveFinishedExecution = false;
}

void Animation::Update()
{
	if (!IsTimeToChangeFrame() || (!haveLoop && haveFinishedExecution))
		return;

	ChangeCurrentFrame();
	setSpriteTo(frames[currentFrame]);
}
bool Animation::IsTimeToChangeFrame()
{
	float currentTime = HardwareManager::GetCurrentSeconds();
	return currentTime - lastFrameChangeTime >= intervalBetweenFrames;
}

void Animation::ChangeCurrentFrame()
{
	lastFrameChangeTime = HardwareManager::GetCurrentSeconds();

	currentFrame++;
	if (currentFrame >= framesAmount) ResetCurrentFrame();
}
void Animation::ResetCurrentFrame()
{
	if (haveLoop)
		currentFrame = 0;
	else
		FinishAnimation();
}
void Animation::FinishAnimation()
{
	haveFinishedExecution = true;
	currentFrame = framesAmount - 1;
}

bool Animation::HaveFinishedExecution()
{
	return haveFinishedExecution;
}