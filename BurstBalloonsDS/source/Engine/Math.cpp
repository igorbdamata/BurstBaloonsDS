#include <iostream>
#include "Engine/Math.h"

int Math::RandomInRange(int lowestInclusiveValue, int highestExclusiveValue)
{
	return lowestInclusiveValue + rand() % (highestExclusiveValue - lowestInclusiveValue);
}

bool Math::InRange(float lowestValue, float highestValue, float valueToCheck)
{
	return (valueToCheck - highestValue) * (valueToCheck - lowestValue) <= 0;
}