#include "stdafx.h"
#include "RGColorBlind.h"

#include <iostream>
using namespace std;

RGColorBlind::RGColorBlind()
{
	cout << "\n 예제 : \n5\nRRRBB\nGGBBB\nBBBRR\nBBRRR\nRRRRR";

	cout << "\n\n 입력 :\n";

	Answer();
}

static char arr[101][101];
static bool chk[101][101];
static int N;

static int dX[4] = { -1,1,0,0 };
static int dY[4] = { 0,0,-1,1 };

static void DFS(int x, int y)
{
	chk[x][y] = true;

	for (int i = 0; i < 4; ++i)
	{
		int newX = x + dX[i];
		int newY = y + dY[i];

		if (newX < 0 || newX >= N
			|| newY < 0 || newY >= N)
			continue;

		if (!chk[newX][newY] && arr[x][y] == arr[newX][newY])
		{
			DFS(newX, newY);
		}
	}
}

void RGColorBlind::Answer()
{
	int ans = 0;

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!chk[i][j])
			{
				DFS(i, j);
				++ans;
			}
		}
	}

	cout << ans <<' ';

	ans = 0;
	memset(chk, false, sizeof(chk));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (arr[i][j] == 'R')
				arr[i][j] = 'G';
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!chk[i][j])
			{
				DFS(i, j);
				++ans;
			}
		}
	}

	cout << ans;
}

void RGColorBlind::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 2108KB";
	cout << "\n 시간		: 0ms ";
	cout << "\n 코드길이	: 1006B";
}
