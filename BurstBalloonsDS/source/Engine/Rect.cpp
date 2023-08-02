#include "Engine/Rect.h"
#include "Engine/HardwareManager.h"

Rect::Rect(Vector2* position, Vector2* offset, float width, float height)
{
	this->position = position;
	this->offset = offset;
	this->width = width;
	this->height = height;
}

float Rect::GetLeftEdge()
{
	return  position->x + offset->x;
}
float Rect::GetUnpositionedLeftEdge()
{
	return  offset->x;
}

float Rect::GetRightEdge()
{
	return  position->x + GetUnpositionedRightEdge();
}
float Rect::GetUnpositionedRightEdge()
{
	return  offset->x + width;
}

float Rect::GetTopEdge()
{
	return  position->y + GetUnpositionedTopEdge();
}
float Rect::GetUnpositionedTopEdge()
{
	return   offset->y;
}

float Rect::GetBottomEdge()
{
	return  position->y + GetUnpositionedBottomEdge();
}
float Rect::GetUnpositionedBottomEdge()
{
	return  offset->y + height;
}

bool Rect::IsOutOfScreen()
{
	return !IsCollidingWith(HardwareManager::screenRect);
}
bool Rect::IsCollidingWith(Vector2* point)
{
	bool isBetweenHorizontalEdges = InRange(GetLeftEdge(), GetRightEdge(), point->x);
	bool isBetweenVerticalEdges = InRange(GetTopEdge(), GetBottomEdge(), point->y);
	return  isBetweenHorizontalEdges && isBetweenVerticalEdges;
}
bool Rect::InRange(float lowestValue, float highestValue, float valueToCheck)
{
	return (valueToCheck - highestValue) * (valueToCheck - lowestValue) <= 0;
}

bool Rect::IsCollidingWith(Rect* rect)
{
	bool isCollidingHorizontally = GetLeftEdge() < rect->GetRightEdge() && GetRightEdge() > rect->GetLeftEdge();
	bool isCollidingVertically = GetTopEdge() < rect->GetBottomEdge() && GetBottomEdge() > rect->GetTopEdge();
	return isCollidingHorizontally && isCollidingVertically;
}

bool Rect::IsBelow(Rect* rect)
{
	return GetTopEdge() > rect->GetBottomEdge();
}
bool Rect::IsAbove(Rect* rect)
{
	return GetBottomEdge() < rect->GetTopEdge();
}
bool Rect::IsOnTheRigth(Rect* rect)
{
	return GetLeftEdge() > rect->GetRightEdge();
}
bool Rect::IsOnTheLeft(Rect* rect)
{
	return GetRightEdge() < rect->GetLeftEdge();
}