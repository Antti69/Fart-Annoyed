#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Colors.h"
#include "Vec2.h"

class Area
{
public:
	Area() = default;
	Area(const RectF& rect_in, Color c_in);
	void DrawWall(Graphics& gfx) const;
	void DrawLife(Graphics& gfx) const;
	void DrawBlueMeter(Graphics& gfx) const;
	void SetLife(char merkki);
	int GetLife() const;
	RectF GetRect() const;
	
private:
	RectF rect;
	Color c;
	int life = 4;

	
};