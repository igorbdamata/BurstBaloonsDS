#pragma once
class MathDS
{
public:
	static int RandomInRange(int lowestInclusiveValue, int highestExclusiveValue);
	static bool InRange(float lowestValue, float highestValue, float valueToCheck);
};