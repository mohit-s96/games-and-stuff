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

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void DrawPoop(int x, int y);
	void DrawStartScreen(int x, int y);
	void DrawEndScreen(int x, int y);
	void DrawPlayer(int x, int y);
	char overshoot(int x, int y, int width, int height);
	bool overlap(int px, int py, int pox, int poy, int dim1, int dim2);
	int resize(int x, int dimension, char ch);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	int playerX = 390, playerY = 290;
	int poop0X = 100, poop0Y = 100;
	int poop1X = 100, poop1Y = 500;
	int poop2X = 700, poop2Y = 300;
	bool isEaten0 = false;
	bool isEaten1 = false;
	bool isEaten2 = false;
	bool gameOver = false;
	bool gameStart = false;
	int flagY0 = 3;
	int flagX0 = 3;
	int flagY1 = 3;
	int flagX1 = 3;
	int flagX2 = 3;
	int flagY2 = 3;
	/********************************/
};