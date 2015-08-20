#pragma once

class Vector2
{
public:
	Vector2();
	Vector2(float initialX, float initialY);
	void SetXY(float newX, float newY);

private:

public:
	float x;
	float y;
};