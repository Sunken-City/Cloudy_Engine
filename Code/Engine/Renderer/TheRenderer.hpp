#pragma once

#include <string>
#include "Engine/Renderer/RGBA.hpp"

class Vector2;
class Vector3;
class AABB2;
class AABB3;
class Texture;
class BitmapFont;

class TheRenderer
{
public:
	TheRenderer();
	void ClearScreen(float red, float green, float blue);
	void ClearScreen(const RGBA& color);
	void SetOrtho(const Vector2& bottomLeft, const Vector2& topRight);
	void SetPerspective(float fovDegreesY, float aspect, float nearDist, float farDist);
	void SetColor(float red, float green, float blue, float alpha);
	void SetColor(const RGBA& color);
	void SetPointSize(float size);
	void PushMatrix();
	void PopMatrix();
	void Translate(float x, float y, float z);
	void Translate(const Vector2& xy);
	void Translate(const Vector3& xyz);
	void Rotate(float rotationDegrees);
	void Rotate(float rotationDegrees, float x, float y, float z);
	void Scale(float x, float y, float z);
	void EnableAdditiveBlending();
	void EnableAlphaBlending();
	void EnableDepthTest(bool enabled);

	void RenderTestCube(const Texture& texture, const AABB2& bounds);
	void RenderTestCube(const Texture& texture, const AABB2& topBounds, const AABB2& bottomBounds, const AABB2& sideBounds);

	void DrawPoint(const Vector2& point);
	void DrawPoint(float x, float y);
	void DrawLine(const Vector2& start, const Vector2& end, float lineThickness);
	void DrawLine(const Vector3& start, const Vector3& end, float lineThickness);
	void DrawLines(Vector2* const* verts, int numVerts, float lineThickness);
	void DrawLineLoop(Vector2* const* verts, int numVerts, float lineThickness);
	void DrawAABB(const AABB2& bounds, const RGBA& color = RGBA::WHITE);
	void DrawTexturedAABB(const AABB2& bounds, const Vector2& texCoordMins, const Vector2& texCoordMaxs, const Texture& texture, const RGBA& color);
	void DrawPolygonOutline(const Vector2& center, float radius, int numSides, float radianOffset);
	void DrawPolygon(const Vector2& center, float radius, int numSides, float radianOffset);
	void DrawText2D(const Vector2& startBottomLeft, const std::string& asciiText, float cellWidth, float cellHeight, const RGBA& tint = RGBA::WHITE, const BitmapFont* font = nullptr);


	static TheRenderer* instance;

	static const int CIRCLE_SIDES = 50;
	static const int HEXAGON_SIDES = 6;
private:
	BitmapFont* m_defaultFont;
};