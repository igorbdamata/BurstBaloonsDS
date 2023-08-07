#pragma once
#if !defined(HARDWARE_DATA)
#define HARDWARE_DATA true
#include "../Engine/Rect.h"

class HardwareData
{
public:
	static const int COLORS_PER_PALETTE = 16;
	static const double CPU_CLOCK;
	static const int MILLISECONDS_PER_TIMER_LOOP = 125000;
	static Rect* screenRect;
};

#endif