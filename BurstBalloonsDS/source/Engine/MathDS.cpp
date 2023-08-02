#include "Engine/MathDS.h"
#include <iostream>

int MathDS::RandomInRange(int lowestInclusiveValue, int highestExclusiveValue)
{
	return lowestInclusiveValue + rand() % (highestExclusiveValue - lowestInclusiveValue);
}