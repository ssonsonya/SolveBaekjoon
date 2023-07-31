#include "stdafx.h"
#include "DownHill.h"

#include <iostream>
using namespace std;

DownHill::DownHill()
{
	cout << "\n 예제 :\n4 5\n50 45 37 32 30\n35 50 40 20 25\n30 30 25 17 28\n27 24 22 15 10";

	cout << "\n\n 입력 :\n";

	Answer();
}

static int M, N;
static int map[501][501];
static int dp[501][501];
static int ans;

static int dX[4] = { -1,1,0,0 };
static int dY[4] = { 0,0,-1,1 };

static int DFS(int y, int x)
{
	if (y == M - 1 && x == N - 1)
		return 1;
	if (dp[y][x] != -1)
		return dp[y][x];

	dp[y][x] = 0;

	for (int i = 0; i < 4; ++i)
	{
		int newX = x + dX[i];
		int newY = y + dY[i];

		if (newX < 0 || newX >= N || newY < 0 || newY >= M)
			continue;

		if (map[newY][newX] < map[y][x])
			dp[y][x] = dp[y][x] + DFS(newY, newX);
	}

	return dp[y][x];
}

void DownHill::Answer()
{
	cin >> M >> N;

	start = clock();

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int input = 0;
			cin >> input;

			map[i][j] = input;
			dp[i][j] = -1;
		}
	}

	ans = DFS(0, 0);

	cout << ans;
	end = clock();
}

#include <cstring>

DownHill::~DownHill()
{
	memset(map, 0, sizeof(map));
	memset(dp, 0, sizeof(dp));

	ans = 0;
}

void DownHill::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 3980 KB";
	cout << "\n 시간		: 108 ms " << end - start;
	cout << "\n 코드길이	: 753B";
}
