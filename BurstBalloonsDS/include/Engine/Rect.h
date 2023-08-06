#pragma once
#if !defined(RECT_H)
#define RECT_H true
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

	bool IsBelow(Rect* rect);
	bool IsAbove(Rect* rect);
	bool IsOnTheRight(Rect* rect);
	bool IsOnTheLeft(Rect* rect);

	bool IsOutOfScreen();
	bool IsCollidingWith(Vector2* point);
	bool IsCollidingWith(Rect* rect);

private:
	Vector2* position;
	Vector2* offset;
	float width;
	float height;
};
#endif