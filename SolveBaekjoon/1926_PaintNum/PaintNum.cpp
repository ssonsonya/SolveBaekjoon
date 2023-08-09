#include "stdafx.h"
#include "PaintNum.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

PaintNum::PaintNum()
{
	cout << "\n 예제 1:\n6 5\n1 1 0 1 1\n0 1 1 0 0\n0 0 0 0 0\n1 0 1 1 1\n0 0 1 1 1\n0 0 1 1 1";
	cout << "\n\n 입력 :\n";

	Answer();
}

static int n, m;

static int canvas[501][501];
static bool chk[501][501];

static int dX[4] = { -1,1,0,0 };
static int dY[4] = { 0,0,-1,1 };

static int area;
static vector<int> areas;

static void DFS(int y, int x)
{
	++area;
	chk[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int newX = x + dX[i];
		int newY = y + dY[i];

		if (newX < 0 || newX >= m || newY < 0 || newY >= n)
			continue;

		if (!chk[newY][newX] && canvas[newY][newX] == 1)
			DFS(newY, newX);
	}
}

void PaintNum::Answer()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> canvas[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			area = 0;
			if (!chk[i][j] && canvas[i][j] == 1)
			{
				DFS(i, j);
				areas.push_back(area);
			}
		}
	}

	sort(areas.begin(), areas.end());

	if (areas.size() == 0)
		cout << 0 << '\n' << 0;
	else
	{
		cout << areas.size() << '\n';
		cout << areas.at(areas.size() - 1);
	}
}

PaintNum::~PaintNum()
{

}

void PaintNum::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 10936 KB";
	cout << "\n 시간		: 28 ms ";
	cout << "\n 코드길이	: 1046 B";
}
