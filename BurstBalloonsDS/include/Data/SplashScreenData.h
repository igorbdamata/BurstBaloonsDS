#pragma once
#if !defined(SPLASH_SCREEN_DATA_H)
#define SPLASH_SCREEN_DATA_H true
#include "../Engine/Vector2.h"

class SplashScreenData
{
public:
	static const float INTERVAL_BETWEEN_FRAMES;
	static const void* FRAMES[];
	static const int FRAMES_COUNT = 5;

	static const bool HAVE_LOOP = false;

	static const float SECONDS_TO_START_FADE_OUT;

	static Vector2* pressAnyKeyInitialPosition;
	static Vector2* pressAnyKeyFinalPosition;
};
#endif