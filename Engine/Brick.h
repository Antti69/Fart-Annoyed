#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Colors.h"
#include "Ball.h"
#include "Paddle.h"

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
		MeterUp,
		MeterFull,
		Catcher,
		MultipleBalls,
		LargePad
	};

public:
	Brick() = default;
	Brick(const RectF& rect_in, Color c_in);
	void Draw(Graphics& gfx) const;
	bool CheckBallCollision(const Ball& ball) const;
	void ExecuteBallCollision(Ball& ball);
	bool CheckAmmoCollision(const Paddle::Guns& gun) const;
	RectF GetRect() const;
	Vec2 GetCenter() const;
	Color GetColor() const;
	Color ColorPulse(Color c);
	void SetColor();
	bool GetFirstcol();
	bool GetDestroyed();
	void SetDestr();
	void Setfirstcol();
	bool indestructible = false;
	bool ColorChange = false;
	
private:
	static constexpr float padding = 1.0f;
	RectF rect;
	Color c;
	bool destroyed = false;
	bool firstcol = false;
	bool increasing = true;
};