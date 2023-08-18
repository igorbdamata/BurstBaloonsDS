#include <iostream>
#include <cmath>

#include "Engine/Math.h"
#include "Engine/HardwareManager.h"

int Math::RandomInRange(int lowestInclusiveValue, int highestExclusiveValue)
{
	return lowestInclusiveValue + rand() % (highestExclusiveValue - lowestInclusiveValue);
}

bool Math::InRange(float lowestValue, float highestValue, float valueToCheck)
{
	return (valueToCheck - highestValue) * (valueToCheck - lowestValue) <= 0;
}

float Math::GetMovementAmountFromWaveWith(float frequency, float amplitude, float offset)
{
	return sin((HardwareManager::GetCurrentSeconds() + offset) * frequency) * amplitude;
}