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
		MultipleBalls,
		LargePad
	};

public:
	Brick() = default;
	Brick(const RectF& rect_in, Color c_in);
	void Draw(Graphics& gfx) const;
	bool CheckBallCollision(const Ball& ball) const;
	bool ExecuteBallCollision(Ball& ball);
	void FlashEffect();
	RectF GetRect() const;
	Vec2 GetCenter() const;
	Color GetColor() const;
	void SetColor(Color c);
	bool GetFirstcol();
	bool GetDestroyed();
	void SetDestr();
	void Setfirstcol();
	bool indestructible = false;
	Color c;
private:
	static constexpr float padding = 1.0f;
	RectF rect;

	bool destroyed = false;
	bool firstcol = false;
	float flashstart = 0.0f;
	float flashend = 0.2f;
};