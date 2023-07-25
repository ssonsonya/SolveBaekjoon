#include "stdafx.h"
#include "IslandNum.h"

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

IslandNum::IslandNum()
{
	cout << "\n 예제 :\n1 1\n0\n2 2\n0 1\n1 0\n3 2\n1 1 1\n1 1 1\n5 4\n1 0 1 0 0\n1 0 0 0 0\n1 0 1 0 1\n1 0 0 1 0\n5 4\n1 1 1 0 1\n1 0 1 0 1\n1 0 1 0 1\n1 0 1 1 1\n5 5\n1 0 1 0 1\n0 0 0 0 0\n1 0 1 0 1\n0 0 0 0 0\n1 0 1 0 1\n0 0";

	cout << "\n\n 입력 :\n";

	Answer();
}

static int w, h;
static int arr[51][51];
static bool chk[51][51];

static int dX[8] = { -1,-1,0,1,1,1,0,-1 };
static int dY[8] = { 0,1,1,1,0,-1,-1,-1 };

static void DFS(int y, int x)
{
	chk[y][x] = true;

	for (int i = 0; i < 8; ++i)
	{
		int newX = x + dX[i];
		int newY = y + dY[i];

		if (newX < 0 || newX > w
			|| newY <0 || newY >h)
			continue;

		if (arr[newY][newX] == 1 && !chk[newY][newX])
			DFS(newY, newX);
	}

}

void IslandNum::Answer()
{
	vector<int> ans;

	do
	{
		int num = 0;
		memset(arr, 0, sizeof(arr));
		memset(chk, 0, sizeof(chk));

		cin >> w >> h;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
				cin >> arr[i][j];
		}

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (arr[i][j] == 1 && !chk[i][j])
				{
					DFS(i, j);
					++num;
				}
			}
		}
		ans.push_back(num);
	} while (w > 0 && h > 0);

	ans.resize(ans.size() - 1);

	for (auto a : ans)
		cout << a << '\n';
}

void IslandNum::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 2032KB";
	cout << "\n 시간		: 4ms ";
	cout << "\n 코드길이	: 977B";
}
