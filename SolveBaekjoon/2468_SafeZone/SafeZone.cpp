#include "stdafx.h"
#include "SafeZone.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

SafeZone::SafeZone()
{
	cout << "\n 예제 1 :\n5\n6 8 2 6 2\n3 2 3 4 6\n6 7 3 3 2\n7 2 5 3 6\n8 9 5 2 7";
	cout << "\n 예제 2 :\n7\n9 9 9 9 9 9 9\n9 2 1 2 1 2 9\n9 1 8 7 8 1 9\n9 2 7 9 7 2 9\n9 1 8 7 8 1 9\n9 2 1 2 1 2 9\n9 9 9 9 9 9 9";


	cout << "\n\n 입력 :\n";

	Answer();
}

static int N;
static int arr[101][101];
static bool chk[101][101];
static int rainfall;
static int dX[4] = { -1,1,0,0 };
static int dY[4] = { 0,0,-1,1 };

SafeZone::~SafeZone()
{
	memset(arr, 0, sizeof(arr));
	rainfall = 0;
}

static void DFS(int x, int y)
{
	chk[x][y] = true;

	for (int i = 0; i < 4; ++i)
	{
		int newX = x + dX[i];
		int newY = y + dY[i];

		if (newX < 0 || newX > N || newY < 0 || newY > N)
			continue;

		if (!chk[newX][newY] && arr[newX][newY] > rainfall)
			DFS(newX, newY);
	}
}

void SafeZone::Answer()
{
	vector<int> ans;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int x = 0;

			cin >> x;

			arr[i][j] = x;
		}
	}

	while (rainfall <= 100)
	{
		int num = 0;
		memset(chk, false, sizeof(chk));

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (!chk[i][j] && arr[i][j] > rainfall)
				{
					DFS(i, j);
					++num;
				}
			}
		}
		ans.push_back(num);
		++rainfall;
	}

	sort(ans.begin(), ans.end());
	
	cout << ans[(int)ans.size() - 1];
}

void SafeZone::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 2268KB";
	cout << "\n 시간		: 16ms";
	cout << "\n 코드길이	: 1001B";
}
