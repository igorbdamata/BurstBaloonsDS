#include "Engine/Rect.h"
#include "Engine/Math.h"
#include "Data/HardwareData.h"

Rect::Rect(Vector2* position, Vector2* offset, float width, float height)
{
	this->position = position;
	this->offset = offset;
	this->width = width;
	this->height = height;
}

bool Rect::IsBelow(Rect* rect)
{
	return GetTopEdge() > rect->GetBottomEdge();
}
bool Rect::IsAbove(Rect* rect)
{
	return GetBottomEdge() < rect->GetTopEdge();
}
bool Rect::IsOnTheRight(Rect* rect)
{
	return GetLeftEdge() > rect->GetRightEdge();
}
bool Rect::IsOnTheLeft(Rect* rect)
{
	return GetRightEdge() < rect->GetLeftEdge();
}

bool Rect::IsOutOfScreen()
{
	return !IsCollidingWith(HardwareData::screenRect);
}
bool Rect::IsCollidingWith(Vector2* point)
{
	bool isBetweenHorizontalEdges = Math::InRange(GetLeftEdge(), GetRightEdge(), point->x);
	bool isBetweenVerticalEdges = Math::InRange(GetTopEdge(), GetBottomEdge(), point->y);
	return  isBetweenHorizontalEdges && isBetweenVerticalEdges;
}

bool Rect::IsCollidingWith(Rect* rect)
{
	bool isCollidingHorizontally = GetLeftEdge() < rect->GetRightEdge() && GetRightEdge() > rect->GetLeftEdge();
	bool isCollidingVertically = GetTopEdge() < rect->GetBottomEdge() && GetBottomEdge() > rect->GetTopEdge();
	return isCollidingHorizontally && isCollidingVertically;
}