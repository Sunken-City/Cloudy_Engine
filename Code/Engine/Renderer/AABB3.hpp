#pragma once
#include "Engine/Math/Vector3.hpp"

class AABB3
{
public:
	AABB3();
	AABB3(const Vector3& Mins, const Vector3& Maxs);
	~AABB3();

	Vector3 mins;
	Vector3 maxs;
private:

};
