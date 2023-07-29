#pragma once
#if !defined(CODED_ANIMATION_H)
#define CODED_ANIMATION_H 1
class CodedAnimation
{
public:
	virtual void Start();
	virtual void Update();
	virtual void Stop();
	virtual bool HaveFinished();
	virtual bool IsPlaying();
private:
	bool isPlaying;
};
#endif