#include "Area.h"

Area::Area(const RectF& rect_in, Color c_in)
	:
	rect(rect_in),
	c(c_in)
	
{}

void Area::Draw(Graphics & gfx) const
{
	gfx.DrawRect(rect, c);
}

RectF Area::GetRect() const
{
	return rect;
}
