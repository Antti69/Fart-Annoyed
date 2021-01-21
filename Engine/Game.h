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
#include <random>

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();

	enum class Level
	{
		Lvl1,
		Lvl2,
		Lvl3,
		Lvl4,
		Lvl5,
		Lvl6,
		Lvl7,
		Lvl8,
		Lvl9,
		Testi
	};
	Level level = { Level::Lvl1 };
private:
	void ComposeFrame();
	void UpdateModel(float dt);

private:
	MainWindow& wnd;
	Graphics gfx;

	void BrickCollision(Brick* bricks, Brick::State* state, Ball& ball, int BrickTotal_lvl1, float dt);
	void BrickCollision(Brick* bricks, Brick::State* state, Ball& ball, Ball& ball2, Ball& ball3, int BrickTotal_lvl1, float dt)
	{
		BrickCollision(bricks, state, ball, BrickTotal_lvl1, dt);			//float dt testejä varten
		BrickCollision(bricks, state, ball2, BrickTotal_lvl1, dt);
		BrickCollision(bricks, state, ball3, BrickTotal_lvl1, dt);
	}
	
	void DrawTitle();
	void DrawOver();
	void DrawLevel(const Level level);
	void Timer(float dt);
	float dt;
	float elapsedTime;

	static constexpr float brickWidth = 40.0;			//Brickkien arvot ja säädöt
	static constexpr float brickHeight = 18.0f;
	static constexpr int BrickViisto_lvl1 = 8;					//14 max
	static constexpr int BrickPysty_lvl1 = 5;
	static constexpr int BrickTotal_lvl1 = BrickViisto_lvl1 * BrickPysty_lvl1;

	static constexpr int BrickViisto_lvl2 = 10;
	static constexpr int BrickPysty_lvl2 = 6;
	static constexpr int BrickTotal_lvl2 = BrickViisto_lvl2 * BrickPysty_lvl2;

	static constexpr int BrickViisto_lvl3 = 2;
	static constexpr int BrickPysty_lvl3 = 10;
	static constexpr int BrickTotal_lvl3 = BrickViisto_lvl3 * BrickPysty_lvl3;

	static constexpr int BrickViisto_lvl3_1 = 3;
	static constexpr int BrickPysty_lvl3_1 = 5;
	static constexpr int BrickTotal_lvl3_1 = BrickViisto_lvl3_1 * BrickPysty_lvl3_1;

	static constexpr int BrickViisto_lvl4 = 14;
	static constexpr int BrickPysty_lvl4 = 9;
	static constexpr int BrickTotal_lvl4 = BrickViisto_lvl4 * BrickPysty_lvl4;

	static constexpr int BrickViisto_lvl5 = 12;
	static constexpr int BrickPysty_lvl5 = 12;
	static constexpr int BrickTotal_lvl5 = BrickViisto_lvl5 + BrickPysty_lvl5;

	static constexpr int BrickViisto_lvl5_1 = 5;
	static constexpr int BrickPysty_lvl5_1 = 4;
	static constexpr int BrickTotal_lvl5_1 = BrickViisto_lvl5_1 * BrickPysty_lvl5_1;

	static constexpr int BrickViisto_lvl6 = 10;
	static constexpr int BrickPysty_lvl6 = 8;
	static constexpr int BrickTotal_lvl6 = BrickViisto_lvl6 * BrickPysty_lvl6;

	static constexpr int BrickViisto_lvl7 = 10;
	static constexpr int BrickPysty_lvl7 = 2;
	static constexpr int BrickTotal_lvl7 = BrickViisto_lvl7 * BrickPysty_lvl7;

	static constexpr int BrickViisto_lvl7_1 = 12;
	static constexpr int BrickPysty_lvl7_1 = 10;
	static constexpr int BrickTotal_lvl7_1 = BrickViisto_lvl7_1 * BrickPysty_lvl7_1;

	static constexpr int BrickViisto_lvl8 = 2;
	static constexpr int BrickPysty_lvl8 = 2;
	static constexpr int BrickTotal_lvl8 = BrickViisto_lvl8 * BrickPysty_lvl8;

	static constexpr int BrickViisto_lvlTesti = 2;
	static constexpr int BrickPysty_lvlTesti = 2;
	static constexpr int BrickTotal_lvlTesti = BrickViisto_lvlTesti * BrickPysty_lvlTesti;

	static constexpr float GridStartX = 120.0f;
	static constexpr float GridStartY = 60.0f;

	FrameTimer ft;											//objektit
	Paddle pad{ Vec2(400.0f, 520.0f), 40.0f, 10.0f };
	Ball ball = { Vec2(pad.GetRect().GetCenter().x, pad.GetRect().GetCenter().y - 20.0f), Vec2(200.0f, 200.0f) };
	Ball ball2;
	Ball ball3;
	Area::Life life;
	Area::Meter meter;
	Paddle::Guns gun = { Vec2(pad.GetPos()) };
	

	Brick bricks[BrickTotal_lvl1];
	Brick bricks2[BrickTotal_lvl2];
	Brick bricks3[BrickTotal_lvl3];
	Brick bricks3_1[BrickTotal_lvl3_1];
	Brick bricks4[BrickTotal_lvl4];
	Brick bricks5[BrickTotal_lvl5];
	Brick bricks5_1[BrickTotal_lvl5_1];
	Brick bricks6[BrickTotal_lvl6];
	Brick bricks7[BrickTotal_lvl7];
	Brick bricks7_1[BrickTotal_lvl7_1];
	Brick bricks8[BrickTotal_lvl8];


	Brick bricksTesti[BrickTotal_lvlTesti];

	Brick::State state[BrickTotal_lvl1] = { Brick::State::Basic };
	Brick::State state2[BrickTotal_lvl2] = { Brick::State::Basic };
	Brick::State state3[BrickTotal_lvl3] = { Brick::State::Basic };
	Brick::State state3_1[BrickTotal_lvl3_1] = { Brick::State::Basic };
	Brick::State state4[BrickTotal_lvl4] = { Brick::State::Basic };
	Brick::State state5[BrickTotal_lvl5] = { Brick::State::Basic };
	Brick::State state5_1[BrickTotal_lvl5_1] = { Brick::State::Basic };
	Brick::State state6[BrickTotal_lvl6] = { Brick::State::Basic };
	Brick::State state7[BrickTotal_lvl7] = { Brick::State::Basic };
	Brick::State state7_1[BrickTotal_lvl7_1] = { Brick::State::Basic };
	Brick::State state8[BrickTotal_lvl8] = { Brick::State::Basic };

	Brick::State stateTesti[BrickTotal_lvlTesti] = { Brick::State::Basic };


	Area leftwall = { RectF(110.0f, GridStartX , GridStartY, gfx.ScreenHeight), Colors::Blue };		//pelialueen säätö
	Area rightwall = { RectF(680.0f, 690.0f, GridStartY, gfx.ScreenHeight), Colors::Blue };
	Area topwall = { RectF(110.0f, 690.0f, 50.0f, GridStartY), Colors::Blue };

	RectF walls = { RectF(leftwall.GetRect().right, rightwall.GetRect().left, topwall.GetRect().bottom, float(gfx.ScreenHeight)) };

	
	bool Started = false;
	bool GameOver = false;
	bool ChoiceState = false;
	bool ChoiceState2 = false;
	bool LvlUp = false;
	bool Ball_1 = true;
	bool Ball_2 = false;
	bool Ball_3 = false;
	
};