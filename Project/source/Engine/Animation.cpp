#include "Engine\Animation.h"
#include "Engine\HardwareManager.h"

Animation::Animation(float framesInterval, int firstFrame, int lastFrame, void *sprite, SpriteSize spritesSize, void *spriteSheet, int spriteSheetWidth, bool haveLoop)
{
    this->framesInterval = framesInterval;
    this->firstFrame = firstFrame;
    this->lastFrame = lastFrame;
    this->sprite = sprite;
    this->spriteSheet = spriteSheet;
    this->spriteSheetWidth = spriteSheetWidth;
    this->spritesSize = spritesSize;
    this->haveLoop = haveLoop;
    this->finishedExecution = false;
}

bool Animation::IsPlaying()
{
    return isPlaying;
}

void Animation::Start()
{
    currentFrame = firstFrame;
    finishedExecution = false;
}

void Animation::Update()
{
    if (!IsTimeToChangeFrame() || (!haveLoop && finishedExecution))
        return;

    ChangeFrame();
    CopySpriteIntoMemory();
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
    if (currentFrame <= lastFrame)
        return;
    ResetCurrentFrame();
}
void Animation::ResetCurrentFrame()
{
    if (haveLoop)
    {
        currentFrame = firstFrame;
        return;
    }
    FinishAnimation();
}
void Animation::FinishAnimation()
{
    finishedExecution = true;
    currentFrame = lastFrame;
}

void Animation::CopySpriteIntoMemory()
{
    DC_FlushAll();
    dmaCopy(
        spriteSheet + (spriteSheetWidth)*currentFrame,
        sprite,
        SpriteSize_64x64);
}