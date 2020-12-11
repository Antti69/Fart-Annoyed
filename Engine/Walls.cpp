#include "Walls.h"

Walls::Walls(const RectF& rect_in, Color c_in)
	:
	rect(rect_in),
	c(c_in)
	
{}

void Walls::Draw(Graphics & gfx) const
{
	gfx.DrawRect(rect, c);
}

RectF Walls::GetRect() const
{
	return rect;
}
