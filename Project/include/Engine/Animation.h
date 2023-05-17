#if !defined(ANIMATION_H)
#define ANIMATION_H 1
#pragma once

#include <nds.h>

class Animation
{
public:
    Animation(float framesInterval, int firstFrame, int lastFrame, u16 *sprite, SpriteSize spritesSize, void *spriteSheet, int spriteSheetWidth, bool haveLoop);

    void Start();
    void Update();

    bool IsPlaying();

private:
    bool isPlaying;
    bool haveLoop;

    int currentFrame;

    int firstFrame;
    int lastFrame;

    float framesInterval;
    float lastFrameChangeTime;

    bool finishedExecution;

    void *sprite;
    void *spriteSheet;

    int spriteSheetWidth;
    SpriteSize spritesSize;

    bool IsTimeToChangeFrame();
    void ChangeFrame();
    void ResetCurrentFrame();
    void FinishAnimation();
    void CopySpriteIntoMemory();
};

#endif