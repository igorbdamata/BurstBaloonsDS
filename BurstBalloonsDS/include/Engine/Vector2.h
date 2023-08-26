#pragma once
#if !defined(VECTOR2_H)
#define VECTOR2_H true

struct Vector2
{
	float x, y;

	Vector2();
	Vector2(float x, float y);

	void Lerp(Vector2* pointA, Vector2* pointB, float percent);
	float DistanceTo(Vector2* point);

	float GetMagnitude();
	void SetMagnitudeTo(float value);
	void Normalize();

	float GetAngleRadians();
	float GetAngleDegrees();

	const Vector2 operator +(Vector2 const& object);
	const Vector2 operator -(Vector2 const& object);
	const Vector2 operator *(float const& value);
	const Vector2 operator /(float const& value);

	const Vector2 operator +=(Vector2 const& object);
	const Vector2 operator -=(Vector2 const& object);
	const Vector2 operator *=(float const& value);
	const Vector2 operator /=(float const& value);

	const bool operator ==(Vector2 const& object);
	const bool operator !=(Vector2 const& object);
};

#endif