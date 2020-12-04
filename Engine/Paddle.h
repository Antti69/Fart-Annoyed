#pragma once
#include "Graphics.h"
#include "Ball.h"
#include "Vec2.h"
#include "Colors.h"
#include "RectF.h"
#include "Keyboard.h"


class Paddle
{
public:
	Paddle(const Vec2& pos_in, float halfWidth_in, float halfHeight_in);
	void Draw(Graphics& gfx);
	bool BallCollision(Ball& ball);
	void WallCollision(const RectF& walls);
	void Movement(Keyboard& kbd, float dt);
	RectF GetRect() const;
	

private:
	Color color = Colors::White;
	Color WingColor = Colors::Red;
	float WingWidth = 10.0f;
	float speed = 400.0f;		
	float MaxExitRation = 3.0f; 
	float eXitFactor;
	float halfWidth;
	float halfHeight;
	Vec2 pos;
	

};