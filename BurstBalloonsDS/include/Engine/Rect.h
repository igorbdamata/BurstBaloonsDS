#pragma once
#if !defined(RECT_H)
#define RECT_H 1
#include"Vector2.h"
struct Rect
{
public:
	Rect(Vector2* position, Vector2* offset, float width, float height);

	float GetLeftEdge();
	float GetRightEdge();
	float GetTopEdge();
	float GetBottomEdge();

	float GetUnpositionedLeftEdge();
	float GetUnpositionedRightEdge();
	float GetUnpositionedTopEdge();
	float GetUnpositionedBottomEdge();

	bool IsCollidingWith(Vector2* point);
	bool IsCollidingWith(Rect* rect);

private:
	Vector2* position;
	Vector2* offset;
	float width;
	float height;

	bool InRange(float lowestValue, float highestValue, float valueToCheck);
};
#endif