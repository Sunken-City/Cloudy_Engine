#pragma once

class Vector3
{
public:
	Vector3();
	Vector3(float initialX, float initialY, float initialZ);
	Vector3(const Vector3& other);
	void SetXYZ(float newX, float newY, float newZ);
	float CalculateMagnitude();
	void Normalize();

	Vector3& operator+=(const Vector3& rhs);
	Vector3& operator-=(const Vector3& rhs);
	Vector3& operator*=(const float& scalarConstant);
private:

public:
	float x;
	float y;
	float z;
};

inline Vector3 operator+(Vector3 lhs, const Vector3& rhs)
{
	lhs += rhs;
	return lhs;
}

inline Vector3 operator-(Vector3 lhs, const Vector3& rhs)
{
	lhs -= rhs;
	return lhs;
}

inline Vector3 operator*(Vector3 lhs, const float& scalarConstant)
{
	lhs *= scalarConstant;
	return lhs;
}

inline bool operator==(const Vector3& lhs, const Vector3& rhs)
{ 
	return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z); 
}

inline bool operator!=(const Vector3& lhs, const Vector3& rhs)
{
	return !(lhs == rhs);
}