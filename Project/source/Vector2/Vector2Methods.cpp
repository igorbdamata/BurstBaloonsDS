#include "../Headers/Vector2.h"
#include <cmath>

Vector2::Vector2()
{
	Vector2(0, 0);
}
Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Vector2::Lerp(Vector2 point, float percent)
{
	return GetMagnitude() + DistanceTo(point) * percent;
}
float Vector2::DistanceTo(Vector2 point)
{
	return  sqrt(pow((x - point.x), 2) + pow((y - point.y), 2));
}

float Vector2::GetMagnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}
void Vector2::SetMagnitudeTo(float newMagnitude)
{
	Normalize();
	x *= newMagnitude;
	y *= newMagnitude;
}
void Vector2::Normalize()
{
	Vector2 selfWithLastMagnitude = Vector2(x, y);
	x = cos(selfWithLastMagnitude.GetAngleRadians());
	y = sin(selfWithLastMagnitude.GetAngleRadians());
}

float Vector2::GetAngleRadians()
{
	return atan2(y, x);;
}
float Vector2::GetAngleDegrees()
{
	return GetAngleRadians() * (180 / 3.14f);
}