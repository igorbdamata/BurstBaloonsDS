#pragma once
#if !defined(GAMEPLAY_SETTINGS_H)
#define GAMEPLAY_SETTINGS_H true
class GameplayData
{
public:
	static const int BALLOONS_COUNT = 5;
	static const int TOTAL_LIFE = 3;
	static const float SECONDS_TO_REACH_MAX_SPEED;
	
	static const float GRAVITY_FORCE;

	static const int DISTANCE_BETWEEN_UI_BALLOONS = 20;
	static const int UI_BALLOON_ALIGNMENT = -3;
};
#endif