#include "Data/SplashScreenData.h"
#include "Data/PressAnyKeyTextData.h";

#include "BackgroundAnimation2.h";
#include "BackgroundAnimation3.h";
#include "BackgroundAnimation4.h";
#include "BackgroundAnimation5.h";
#include "BackgroundAnimation6.h";
#include "BackgroundAnimation7.h";

const float SplashScreenData::INTERVAL_BETWEEN_FRAMES = 0.3f;
const int SplashScreenData::FRAMES_AMOUNT = 5;
const void* SplashScreenData::FRAMES[SplashScreenData::FRAMES_AMOUNT] =
{
	BackgroundAnimation3Bitmap,
	BackgroundAnimation4Bitmap,
	BackgroundAnimation5Bitmap,
	BackgroundAnimation6Bitmap,
	BackgroundAnimation7Bitmap
};

const float SplashScreenData::SECONDS_TO_START_FADE_OUT = 3.0f;

Vector2* SplashScreenData::pressAnyKeyInitialPosition = new Vector2(PressAnyKeyTextData::CENTERED_POSITION_X, 
												 PressAnyKeyTextData::CENTERED_POSITION_Y * 2);
Vector2* SplashScreenData::pressAnyKeyFinalPosition = new Vector2(PressAnyKeyTextData::CENTERED_POSITION_X,  
																  PressAnyKeyTextData::CENTERED_POSITION_Y);