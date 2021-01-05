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

void Area::Meter::DrawBlueMeter(Graphics& gfx) const
{
	const RectF pohja = { Vec2(50.0f, MeterMax), Vec2(70.0f, MeterMin) };
	gfx.DrawRect(pohja, Colors::White);

	gfx.DrawCircle(60, 560, 20, Colors::Blue);

	RectF BlueM = { Vec2(50.0f, b_meterY), Vec2(70.0f, MeterMin) };
	gfx.DrawRect(BlueM, Colors::Blue);
}

void Area::Meter::DrawRedMeter(Graphics& gfx) const
{
	const RectF pohja = { Vec2(740.0f, MeterMax), Vec2(760.0f, MeterMin) };
	gfx.DrawRect(pohja, Colors::White);

	gfx.DrawCircle(750, 560, 20, Colors::Red);

	RectF RedM = { Vec2(740.0f, r_meterY), Vec2(760.0f, MeterMin) };
	gfx.DrawRect(RedM, Colors::Red);
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


int Area::Life::GetLife() const
{
	return life;
}

RectF Area::GetRect() const
{
	return rect;
}

void Area::Meter::SetBlueM(char merkki)
{
	if (BlueMeter)
	{
		if (merkki == '+' && b_meterY > MeterMax)
		{
			b_meterY -= 10.0f;

		}
		if (merkki == '-' && b_meterY < MeterMin)
		{
			b_meterY += 0.1f;
		}
	}
}

void Area::Meter::SetRedM(Life& life)
{
	if (RedMeter)
	{
		r_meterY -= 20.0f;

		if (r_meterY <= MeterMax)
		{
			life.SetLife('+');
			r_meterY = MeterMin;
			
		}
	}

}

float Area::Meter::GetBlueMeter() const
{
	return b_meterY;
}

float Area::Meter::GetMeterMin() const
{
	return MeterMin;
}
