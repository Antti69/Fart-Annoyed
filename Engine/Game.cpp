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
	const Color colors[5] = { Colors::Blue, Colors::Green, Colors::Red, Colors::Yellow, Colors::Gray };
	
	const Vec2 topleft = { 70.0f, 80.0f };		//koordinaatit mistä grid alkaa

	int i = 0;
	for (int y = 0; y < BrickPysty; y++)
	{
		const Color c = colors[y];
		for (int x = 0; x < BrickViisto; x++)
		{
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
			if (CurColIndex < 60)
			{
				bricks[CurColIndex].Setfirstcol();
			}
		}
	}
 	if (Collisionhappend)
	{
		if (bricks[CurColIndex].GetFirstcol())
		{
			bricks[CurColIndex].ExecuteBallCollision(ball);
			pad.ResetCooldown();
			bricks[CurColIndex].SetDestr();
		}
		else
		{
			bricks[CurColIndex].ExecuteBallCollision(ball);
			bricks[CurColIndex].Setfirstcol();
			pad.ResetCooldown();
		}
	}
}

void Game::ComposeFrame()
{
	ball.Draw(gfx);
	pad.Draw(gfx);
	
	for (const Brick& b : bricks)
	{
		b.Draw(gfx);
	}
}
