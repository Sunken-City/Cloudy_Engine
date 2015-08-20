#include "Engine/Math/Vector2.hpp"

Vector2::Vector2() 
	: x(0.0f)
	, y(0.0f)
{
}

Vector2::Vector2(float initialX, float initialY) 
	: x(initialX)
	, y(initialY)
{
}

void Vector2::SetXY(float newX, float NewY)
{
	x = newX;
	y = NewY;
}