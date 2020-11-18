#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Colors.h"

class Brick
{
public:
	Brick(const RectF& rect_in, Color c_in);
	void Draw(Graphics& gfx) const;


private:
	RectF rect;
	Color c;
	bool destroyed = false;
};