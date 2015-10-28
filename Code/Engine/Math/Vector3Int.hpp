#pragma once

class Vector3Int
{
public:
	Vector3Int();
	Vector3Int(int initialX, int initialY, int initialZ);
	Vector3Int(const Vector3Int& other);
	void SetXY(int newX, int newY, int newZ);

	Vector3Int& operator+=(const Vector3Int& rhs);
	Vector3Int& operator-=(const Vector3Int& rhs);
	Vector3Int& operator*=(const int& scalarConstant);

public:
	int x;
	int y;
	int z;
};

inline Vector3Int operator+(Vector3Int lhs, const Vector3Int& rhs)
{
	lhs += rhs;
	return lhs;
}

inline Vector3Int operator-(Vector3Int lhs, const Vector3Int& rhs)
{
	lhs -= rhs;
	return lhs;
}

inline Vector3Int operator*(Vector3Int lhs, const int& scalarConstant)
{
	lhs *= scalarConstant;
	return lhs;
}