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

RectF Area::GetRect() const
{
	return rect;
}

void Area::Life::DrawLife(Graphics& gfx) const
{
	const RectF life1 = { Vec2(550.0f, 20.0f), Vec2(570.0f, 40.0f) };
	const RectF life2 = { Vec2(580.0f, 20.0f), Vec2(600.0f, 40.0f) };
	const RectF life3 = { Vec2(610.0f, 20.0f), Vec2(630.0f, 40.0f) };
	const RectF life4 = { Vec2(640.0f, 20.0f), Vec2(660.0f, 40.0f) };
	const RectF life5 = { Vec2(670.0f, 20.0f), Vec2(690.0f, 40.0f) };
	if (life == 6)
	{
		gfx.DrawRect(life1, Colors::Red);
		gfx.DrawRect(life2, Colors::Red);
		gfx.DrawRect(life3, Colors::Red);
		gfx.DrawRect(life4, Colors::Red);
		gfx.DrawRect(life5, Colors::Red);
	}
	if (life == 5)
	{
		gfx.DrawRect(life1, Colors::Red);
		gfx.DrawRect(life2, Colors::Red);
		gfx.DrawRect(life3, Colors::Red);
		gfx.DrawRect(life4, Colors::Red);
	}
	if (life == 4)
	{
		gfx.DrawRect(life1, Colors::Red);
		gfx.DrawRect(life2, Colors::Red);
		gfx.DrawRect(life3, Colors::Red);
	}
	if (life == 3)
	{
		gfx.DrawRect(life1, Colors::Red);
		gfx.DrawRect(life2, Colors::Red);
	}
	if (life == 2)
	{
		gfx.DrawRect(life1, Colors::Red);
	}
	if (life == 1)
	{

	}
}

void Area::Life::DrawLifeTest(Graphics& gfx) const
{
	const Vec2 life1 = { 510.0f, 15.0f };
	const Vec2 life2 = { 550.0f, 15.0f };
	const Vec2 life3 = { 590.0f, 15.0f };
	const Vec2 life4 = { 630.0f, 15.0f };
	const Vec2 life5 = { 670.0f, 15.0f };

	if (life == 6)
	{
		gfx.DrawSurfaceVec(life1, surf);
		gfx.DrawSurfaceVec(life2, surf);
		gfx.DrawSurfaceVec(life3, surf);
		gfx.DrawSurfaceVec(life4, surf);
		gfx.DrawSurfaceVec(life5, surf);
	}
	if (life == 5)
	{
		gfx.DrawSurfaceVec(life1, surf);
		gfx.DrawSurfaceVec(life2, surf);
		gfx.DrawSurfaceVec(life3, surf);
		gfx.DrawSurfaceVec(life4, surf);
	}
	if (life == 4)
	{
		gfx.DrawSurfaceVec(life1, surf);
		gfx.DrawSurfaceVec(life2, surf);
		gfx.DrawSurfaceVec(life3, surf);
	}
	if (life == 3)
	{
		gfx.DrawSurfaceVec(life1, surf);
		gfx.DrawSurfaceVec(life2, surf);
	}
	if (life == 2)
	{
		gfx.DrawSurfaceVec(life1, surf);
	}
	if (life == 1)
	{

	}
}

int Area::Life::GetLife() const
{
	return life;
}

void Area::Life::SetLife(char merkki)
{
	if (merkki == '+' && life < 7)
	{
		life += 1;
	}
	if (merkki == '-')
	{
		life -= 1;
	}
}

void Area::Meter::DrawMeter(Graphics& gfx, MeterPos& pos, float b_meterY, Color c) const
{
	RectF MeterLeft = { Vec2(50.0f, b_meterY), Vec2(70.0f, MeterMin) };
	RectF MeterRight = { Vec2(740.0f, b_meterY), Vec2(760.0f, MeterMin) };
	switch (pos)
	{
	case MeterPos::None:
		break;

	case MeterPos::Left:
		gfx.DrawRect(pohja_left, Colors::White);
		gfx.DrawCircle(60, 560, 20, c);
		gfx.DrawRect(MeterLeft, c);
		break;

	case MeterPos::Right:
		gfx.DrawRect(pohja_right, Colors::White);
		gfx.DrawCircle(750, 560, 20, c);
		gfx.DrawRect(MeterRight, c);
		break;
	}
}

void Area::Meter::SetBlueM(char merkki)
{
	if (Blue != MeterPos::None )
	{
		if (merkki == '+' && b_meterY > MeterMax)
		{
			b_meterY -= 8.0f;

		}
		if (merkki == '-' && b_meterY < MeterMin)
		{
			b_meterY += 0.1f;
		}
		if (merkki == 'F')
		{
			b_meterY = MeterMax;
		}
	}
}

void Area::Meter::SetRedM(Life& life)
{
	if (Red != MeterPos::None)
	{
		r_meterY -= 10.0f;

		if (r_meterY <= MeterMax)
		{
			life.SetLife('+');
			r_meterY = MeterMin;
		}
	}
}

void Area::Meter::SetGreenM(char merkki)
{
	if (Green != MeterPos::None)
	{
		if (merkki == '+' && g_meterY > MeterMax)
		{
			g_meterY -= 7.0f;

		}
		if (merkki == '-' && g_meterY < MeterMin)
		{
			g_meterY += 19.2f;
		}
		if (merkki == 'F')
		{
			g_meterY = MeterMax;
		}
	}
}

float Area::Meter::GetMeterMin() const
{
	return MeterMin;
}

float Area::Meter::GetG_meterY() const
{
	return g_meterY;
}

float Area::Meter::GetB_meterY() const
{
	return b_meterY;
}

float Area::Meter::GetR_meterY() const
{
	return r_meterY;
}
