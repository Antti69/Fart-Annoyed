/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Brick.h"
#include "Ball.h"
#include "FrameTimer.h"
#include "Paddle.h"
#include "Sound.h"
#include "Area.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel(float dt);

private:
	MainWindow& wnd;
	Graphics gfx;

	void BrickCollision(int BrickTotal);

	static constexpr float brickWidth = 40.0;			//Brickkien arvot ja säädöt
	static constexpr float brickHeight = 18.0f;
	static constexpr int BrickViisto = 14;					//max 14 riviä
	static constexpr int BrickPysty = 15;					//max 15 riviä
	static constexpr int BrickTotal = BrickViisto * BrickPysty;

	static constexpr int BrickViisto_lvl1 = 10;
	static constexpr int BrickPysty_lvl1 = 13;
	static constexpr int BrickTotal_lvl1 = BrickViisto_lvl1 * BrickPysty_lvl1;



	FrameTimer ft;											//objektit
	Paddle pad{ Vec2(400.0f, 520.0f), 40.0f, 10.0f };
	Ball ball = { Vec2(pad.GetRect().GetCenter().x, pad.GetRect().GetCenter().y - 20.0f), Vec2(200.0f, 200.0f) };
	Brick bricks[BrickTotal];
	Brick::State state[BrickTotal_lvl1] = { Brick::State::Basic };

	Area leftwall = { RectF(110.0f, 120.0f, 30.0f, gfx.ScreenHeight), Colors::Blue };		//pelialueen säätö
	Area rightwall = { RectF(680.0f, 690.0f, 30.0f, gfx.ScreenHeight), Colors::Blue };
	Area topwall = { RectF(110.0f, 690.0f, 20.0f, 30.0f), Colors::Blue };

	RectF walls = { RectF(leftwall.GetRect().right, rightwall.GetRect().left, topwall.GetRect().bottom, float(gfx.ScreenHeight)) };
	bool ResetBall = true;
	
	bool lvl1 = true;
	bool lvl2 = false;
};