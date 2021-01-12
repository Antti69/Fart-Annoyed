#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Colors.h"
#include "Ball.h"

class Brick
{
public:
	enum class State
	{
		Basic,
		Broken,
		TwoHit,
		indestructible,
		SpeedUp,
		SpeedDown,
		LifeUp,
		BlueMeterUp,
		RedMeterUp,
		Catcher,
		MultipleBalls
	};

public:
	Brick() = default;
	Brick(const RectF& rect_in, Color c_in);
	void Draw(Graphics& gfx) const;
	bool CheckBallCollision(const Ball& ball) const;
	void ExecuteBallCollision(Ball& ball);
	RectF GetRect() const;
	Vec2 GetCenter() const;
	bool GetFirstcol();
	bool GetDestroyed();
	void SetDestr();
	void Setfirstcol();
	bool indestructible = false;
	
private:
	static constexpr float padding = 1.0f;
	RectF rect;
	Color c;
	bool destroyed = false;
	bool firstcol = false;
	
};