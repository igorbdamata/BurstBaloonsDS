#include <iostream>
#include "Engine/MathDS.h"

int MathDS::RandomInRange(int lowestInclusiveValue, int highestExclusiveValue)
{
	return lowestInclusiveValue + rand() % (highestExclusiveValue - lowestInclusiveValue);
}

bool MathDS::InRange(float lowestValue, float highestValue, float valueToCheck)
{
	return (valueToCheck - highestValue) * (valueToCheck - lowestValue) <= 0;
}