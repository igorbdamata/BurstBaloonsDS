#include "Engine/CodedAnimation.h"

void CodedAnimation::Start() 
{
	isPlaying = true;
	animationHaveFinished = false;
}

void CodedAnimation::Update() {}
bool CodedAnimation::HaveFinished() { return animationHaveFinished; }
bool CodedAnimation::IsPlaying() { return isPlaying; }