#pragma once
#if !defined(CODED_ANIMATION_H)
#define CODED_ANIMATION_H true
class CodedAnimation
{
public:
	virtual void Start();
	virtual void Update();
	virtual bool HaveFinished();
	virtual bool IsPlaying();
protected:
	bool isPlaying;
	bool animationHaveFinished;
};
#endif