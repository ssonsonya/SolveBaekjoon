#include "stdafx.h"
#include "Cheese.h"

#include <iostream>
#include <cstring>
using namespace std;

Cheese::Cheese()
{
	cout << "\n 예제 :\n8 9\n0 0 0 0 0 0 0 0 0\n0 0 0 1 1 0 0 0 0\n0 0 0 1 1 0 1 1 0\n0 0 1 1 1 1 1 1 0\n0 0 1 1 1 1 1 0 0\n0 0 1 1 0 1 1 0 0\n0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0";
	cout << "\n\n 입력 :\n";

	Answer();
}

static int N, M;
static Grid grid[101][101];
static bool chk[101][101];
static int cheeseNum;

static int dR[4] = { -1,1,0,0 };
static int dC[4] = { 0,0,-1,1 };

static void CheckAir(int row, int col)
{
	chk[row][col] = true;

	for (int i = 0; i < 4; ++i)
	{
		int newR = row + dR[i];
		int newC = col + dC[i];

		if (newR < 0 || newR >= N || newC < 0 || newC >= M)
			continue;

		if (grid[newR][newC].cheese == 1)
			++grid[newR][newC].surAir;

		if (!chk[newR][newC] && grid[newR][newC].cheese == 0)
		{
			CheckAir(newR, newC);
		}
	}
}

void Cheese::Answer()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			cin >> grid[i][j].cheese;
	}

	int time = 0;

	do
	{
		cheeseNum = 0;
		memset(chk, false, sizeof(chk));
		++time;

		// Count Outer Air
		CheckAir(0, 0);

		// Melt Cheese
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (grid[i][j].cheese == 1 && grid[i][j].surAir >= 2)
					grid[i][j].cheese = 0;

				else if (grid[i][j].cheese == 1)
					cheeseNum++;

				grid[i][j].surAir = 0;
			}
		}

	} while (cheeseNum > 0);

	cout << time;
}


Cheese::~Cheese()
{
	memset(chk, false, sizeof(chk));
	memset(grid, 0, sizeof(grid));
	cheeseNum = 0;
}

void Cheese::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 2296 KB";
	cout << "\n 시간		: 12 ms ";
	cout << "\n 코드길이	: 1202 B";
}
