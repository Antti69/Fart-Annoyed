#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Colors.h"

class Area
{
public:
	Area() = default;
	Area(const RectF& rect_in, Color c_in);
	void Draw(Graphics& gfx) const;
	RectF GetRect() const;

private:
	RectF rect;
	Color c;
	
};