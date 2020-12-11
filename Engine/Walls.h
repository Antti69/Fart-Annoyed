#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Colors.h"

class Walls
{
public:
	Walls() = default;
	Walls(const RectF& rect_in, Color c_in);
	void Draw(Graphics& gfx) const;
	RectF GetRect() const;

private:
	RectF rect;
	Color c;
	
};