#pragma once

class Vector2
{
public:
	float x, y;

	Vector2();
	Vector2(float x, float y);

	float Lerp(Vector2 point, float percent);
	float DistanceTo(Vector2 point);

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
