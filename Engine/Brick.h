#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Colors.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(const RectF& rect_in, Color c_in);
	void Draw(Graphics& gfx) const;
	bool BallCollision(Ball& ball);
	RectF GetRect();
private:
	static constexpr float padding = 1.0f;
	RectF rect;
	Color c;
	bool destroyed = false;
};