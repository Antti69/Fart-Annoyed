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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	walls(0.0f, float(gfx.ScreenWidth), 0.0f, float(gfx.ScreenHeight))
{
	const Color colors[5] = { Colors::Blue, Colors::Green, Colors::Red, Colors::Yellow, Colors::Gray };

	const Vec2 topleft = { 70.0f, 80.0f };

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
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();
	ball.Movement(dt);
	ball.DoWallCollision(walls);					//muista katsoa AINA mitä päivittää ja piirtää ekana!!!

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
