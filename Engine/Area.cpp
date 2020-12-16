#include "Area.h"

Area::Area(const RectF& rect_in, Color c_in)
	:
	rect(rect_in),
	c(c_in)
	
{}

void Area::DrawWall(Graphics & gfx) const
{
	gfx.DrawRect(rect, c);
}

void Area::DrawLife(Graphics& gfx)
{
	const RectF life1 = { Vec2(550.0f, 20.0f), Vec2(570.0f, 40.0f) };
	const RectF life2 = { Vec2(580.0f, 20.0f), Vec2(600.0f, 40.0f) };
	const RectF life3 = { Vec2(610.0f, 20.0f), Vec2(630.0f, 40.0f) };
	const RectF life4 = { Vec2(640.0f, 20.0f), Vec2(660.0f, 40.0f) };
	const RectF life5 = { Vec2(670.0f, 20.0f), Vec2(690.0f, 40.0f) };
	if (life == 5)
	{
		gfx.DrawRect(life1, Colors::Red);
		gfx.DrawRect(life2, Colors::Red);
		gfx.DrawRect(life3, Colors::Red);
		gfx.DrawRect(life4, Colors::Red);
		gfx.DrawRect(life5, Colors::Red);
	}
	else if (life == 4)
	{
		gfx.DrawRect(life1, Colors::Red);
		gfx.DrawRect(life2, Colors::Red);
		gfx.DrawRect(life3, Colors::Red);
		gfx.DrawRect(life4, Colors::Red);
	}
	else if (life == 3)
	{
		gfx.DrawRect(life1, Colors::Red);
		gfx.DrawRect(life2, Colors::Red);
		gfx.DrawRect(life3, Colors::Red);
	}
	else if (life == 2)
	{
		gfx.DrawRect(life1, Colors::Red);
		gfx.DrawRect(life2, Colors::Red);
	}
	else if (life == 1)
	{
		gfx.DrawRect(life1, Colors::Red);
	}
	else if (life == 0)
	{

	}
}

void Area::SetLife(int life)
{
	this->life = life;
}

int Area::GetLife() const
{
	return life;
}

RectF Area::GetRect() const
{
	return rect;
}
