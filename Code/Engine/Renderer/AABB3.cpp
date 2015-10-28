#include "Engine/Renderer/AABB3.hpp"

AABB3::AABB3()
{
}

AABB3::AABB3(const Vector3& Mins, const Vector3& Maxs) : mins(Mins), maxs(Maxs)
{

}

AABB3::~AABB3()
{
}