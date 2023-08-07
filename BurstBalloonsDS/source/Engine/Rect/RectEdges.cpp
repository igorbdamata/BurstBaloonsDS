#include "Engine/Rect.h"

float Rect::GetLeftEdge()
{
	return position->x + offset->x;
}
float Rect::GetUnpositionedLeftEdge()
{
	return offset->x;
}

float Rect::GetRightEdge()
{
	return position->x + GetUnpositionedRightEdge();
}
float Rect::GetUnpositionedRightEdge()
{
	return offset->x + width;
}

float Rect::GetTopEdge()
{
	return position->y + GetUnpositionedTopEdge();
}
float Rect::GetUnpositionedTopEdge()
{
	return offset->y;
}

float Rect::GetBottomEdge()
{
	return position->y + GetUnpositionedBottomEdge();
}
float Rect::GetUnpositionedBottomEdge()
{
	return offset->y + height;
}