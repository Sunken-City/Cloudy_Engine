#include "Engine/Math/Vector3Int.hpp"
#include <math.h>

Vector3Int::Vector3Int()
{
}

Vector3Int::Vector3Int(int initialX, int initialY, int initialZ) 
	: x(initialX)
	, y(initialY)
	, z(initialZ)
{
}

Vector3Int::Vector3Int(const Vector3Int& other) 
	: x(other.x)
	, y(other.y)
	, z(other.z)
{
}

void Vector3Int::SetXY(int newX, int newY, int newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}

Vector3Int& Vector3Int::operator+=(const Vector3Int& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return *this;
}

Vector3Int& Vector3Int::operator-=(const Vector3Int& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	return *this;
}

Vector3Int& Vector3Int::operator*=(const int& scalarConstant)
{
	this->x *= scalarConstant;
	this->y *= scalarConstant;
	this->z *= scalarConstant;
	return *this;
}