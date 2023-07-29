#include "CodedAnimation.h"

void CodedAnimation::Start() 
{
	isPlaying = true;
}
void CodedAnimation::Stop() 
{
	isPlaying = false;
}

void CodedAnimation::Update() {}
bool CodedAnimation::HaveFinished() { return false; }
bool CodedAnimation::IsPlaying() { return isPlaying; }