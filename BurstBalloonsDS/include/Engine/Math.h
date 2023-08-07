#if !defined(MATH_H)
#define MATH true
#pragma once

class Math
{
public:
	static int RandomInRange(int lowestInclusiveValue, int highestExclusiveValue);
	static bool InRange(float lowestValue, float highestValue, float valueToCheck);
};

#endif