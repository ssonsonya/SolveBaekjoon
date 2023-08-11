#include "stdafx.h"
#include "HungryPanda.h"

#include <iostream>
using namespace std;

HungryPanda::HungryPanda()
{
	cout << "\n 예제 :\n4\n14 9 12 10\n1 11 5 4\n7 15 2 13\n6 3 16 8";
	cout << "\n\n 입력 :\n";

	Answer();
}

static int n;
static int forest[500][500];
static int dp[500][500];

static int dX[4] = { -1,1,0,0 };
static int dY[4] = { 0,0,-1,1 };

static int DFS(int row, int col)
{
	if (dp[row][col] != 0)
		return dp[row][col];

	dp[row][col] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int newX = row + dX[i];
		int newY = col + dY[i];

		if (newX < 0 || newX >= n || newY < 0 || newY >= n)
			continue;

		if (forest[newX][newY] > forest[row][col])
		{
			int temp = DFS(newX, newY) + 1;
			if (temp > dp[row][col])
				dp[row][col] = temp;
		}
	}

	return dp[row][col];
}

void HungryPanda::Answer()
{
	int ans = 0;
	int temp = 0;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> forest[i][j];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			temp = DFS(i, j);
			if (temp > ans)
				ans = temp;
		}
	}
	
	cout << ans;
}

HungryPanda::~HungryPanda()
{
}

void HungryPanda::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 4004 KB";
	cout << "\n 시간		: 36 ms ";
	cout << "\n 코드길이	: 913 B";
}
