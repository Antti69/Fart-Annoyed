/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"
#include "Colors.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	walls(0.0f, float(gfx.ScreenWidth), 0.0f, float(gfx.ScreenHeight))
{
	Color colors[BrickPysty] = { Colors::Blue, Colors::Green, Colors::Red,		//asettaa lähtövärit y akseliin
								 Colors::Yellow, Colors::Cyan, Colors::Gray};
	
	const Vec2 topleft = { 130.0f, 80.0f };										//koordinaatit mistä grid alkaa

	int i = 0;
	for (int y = 0; y < BrickPysty; y++)
	{
		Color c = colors[y];
		for (int x = 0; x < BrickViisto; x++)
		{
			/*if (y >= 2 && x >= 2 && x <= 12)									//tyhjien paikkojen hallinta   toistaiseksi
			{
				continue;
			}*/	
			if (x == 14 )												//värien säätö ainakin toistaseksi
			{
				c = Colors::Cyan;
				state[i] = Brick::State::indestructible;
			}
			else if (y == 5 && x <= 13 )
			{
				c = Colors::Gray;
				state[i] = Brick::State::TwoHit;
			}
			else if (y == 3 && x <= 13)
			{
				state[i] = Brick::State::SpeedUp;
			}
			else if (y == 2)
			{
				state[i] = Brick::State::SpeedDown;
			}
			else
			{
				c = colors[y];
				state[i] = Brick::State::Basic;
			}
			bricks[i] = Brick(RectF(topleft + Vec2(x * brickWidth, y * brickHeight),
				brickWidth, brickHeight), c);
			i++;
		}
	}
	
}

void Game::Go()
{
	gfx.BeginFrame();
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0.0f)
	{
		const float dt = std::min(0.0025f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	if (!ResetBall)
	{
		ball.Movement(dt);
	}
	else
	{
		ball.SetPos(pad);
	}
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		ResetBall = false;
	}
	
	if (ball.DoWallCollision(walls))					
	{
		pad.ResetCooldown();
	}
	pad.Movement(wnd.kbd, dt);
	pad.WallCollision(walls);
	pad.BallCollision(ball);
	
	bool Collisionhappend = false;
	float CurColDist;
	int CurColIndex;
	
	for (int i = 0; i < BrickTotal; i++)
	{
 		if (bricks[i].CheckBallCollision(ball))
		{
			const float newColDist = (ball.GetPos() - bricks[i].GetCenter()).GetLengthSq();
			if (Collisionhappend)
			{
				if (newColDist < CurColDist)
				{
					CurColDist = newColDist;
					CurColIndex = i;
				}
			}
			else
			{
				CurColDist = newColDist;
				CurColIndex = i;
				Collisionhappend = true;
			}
		}
	}
 	if (Collisionhappend)
	{
		bricks[CurColIndex].ExecuteBallCollision(ball);
		pad.ResetCooldown();

		if (state[CurColIndex] == Brick::State::indestructible)
		{

		}
		else if (state[CurColIndex] == Brick::State::Basic)
		{
			bricks[CurColIndex].SetDestr();
		}
		else if (state[CurColIndex] == Brick::State::Broken)
		{
			bricks[CurColIndex].SetDestr();
		}
		else if (state[CurColIndex] == Brick::State::TwoHit)
		{
			bricks[CurColIndex].Setfirstcol();
			state[CurColIndex] = Brick::State::Broken;
		}
		else if (state[CurColIndex] == Brick::State::SpeedUp)
		{
			ball.SetSpeedUp();
			bricks[CurColIndex].SetDestr();
		}
		else if (state[CurColIndex] == Brick::State::SpeedDown)
		{
			ball.SetSpeedDown();
			bricks[CurColIndex].SetDestr();
		}
	}
}

void Game::ComposeFrame()
{
	leftwall.Draw(gfx);
	rightwall.Draw(gfx);
	topwall.Draw(gfx);
	ball.Draw(gfx);
	pad.Draw(gfx);
	
	for (const Brick& b : bricks)
	{
		b.Draw(gfx);
	}
}
