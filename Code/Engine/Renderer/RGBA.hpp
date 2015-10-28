#pragma once

class RGBA
{
public:
	RGBA();
	RGBA(float Red, float Green, float Blue);
	RGBA(float Red, float Green, float Blue, float Alpha);
	~RGBA();

	float red;
	float blue;
	float green;
	float alpha;

	static const RGBA WHITE;
private:

};

inline bool operator==(const RGBA& lhs, const RGBA& rhs){ return (lhs.red == rhs.red) && (lhs.green == rhs.green) && (lhs.blue == rhs.blue) && (lhs.alpha == rhs.alpha); }