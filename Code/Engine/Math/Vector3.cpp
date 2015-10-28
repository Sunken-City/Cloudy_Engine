#include "Engine/Math/Vector3.hpp"
#include "Engine/Math/MathUtils.hpp"
#include <math.h>

Vector3::Vector3()
{
}

Vector3::Vector3(float initialX, float initialY, float initialZ)
	: x(initialX)
	, y(initialY)
	, z(initialZ)
{
}

Vector3::Vector3(const Vector3& other) 
	: x(other.x)
	, y(other.y)
	, z(other.z)
{
}

void Vector3::SetXYZ(float newX, float newY, float newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}

float Vector3::CalculateMagnitude()
{
	return sqrt((x*x) + (y*y) + (z*z));
}

void Vector3::Normalize()
{
	float len = CalculateMagnitude();
	if (len == 0.f)return;
	x /= len;
	y /= len;
	z /= len;
}

Vector3& Vector3::operator+=(const Vector3& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	return *this;
}

Vector3& Vector3::operator*=(const float& scalarConstant)
{
	this->x *= scalarConstant;
	this->y *= scalarConstant;
	this->z *= scalarConstant;
	return *this;
}
