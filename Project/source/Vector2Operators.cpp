#include "Vector2.h"

const Vector2 Vector2::operator + (Vector2 const& object)
{
	return Vector2(x + object.x, y + object.y);
}
const Vector2 Vector2::operator - (Vector2 const& object)
{
	return Vector2(x - object.x, y - object.y);
}
const Vector2 Vector2::operator * (float const& value)
{
	return Vector2(x * value, y * value);
}
const Vector2 Vector2::operator / (float const& value)
{
	return Vector2(x / value, y / value);
}

const Vector2 Vector2::operator += (Vector2 const& object)
{
	Vector2 a = Vector2(x, y) + object;
	x = a.x;
	y = a.y;
	return a;
}
const Vector2 Vector2::operator -= (Vector2 const& object)
{
	Vector2 a = Vector2(x, y) - object;
	x = a.x;
	y = a.y;
	return a;
}
const Vector2 Vector2::operator *= (float const& value)
{
	Vector2 a = Vector2(x, y) * value;
	x = a.x;
	y = a.y;
	return a;
}
const Vector2 Vector2::operator /= (float const& value)
{
	Vector2 a = Vector2(x, y) / value;
	x = a.x;
	y = a.y;
	return a;
}

const bool Vector2::operator == (Vector2 const& object)
{
	return x == object.x && y == object.y;
}
const bool Vector2::operator != (Vector2 const& object)
{
	return x != object.x || y != object.y;
}