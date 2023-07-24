#include "stdafx.h"
#include "Cabbage.h"

#include <iostream>
#include <string.h>
using namespace std;

Cabbage::Cabbage()
{
	Answer();
}

int M_1012, N_1012, K_1012;
int arr_1012[50][50];
int chk_1012[50][50];

int dX_1012[4] = { -1,1,0,0 };
int dY_1012[4] = { 0,0,-1,1 };

void DFS_1012(int y, int x)
{
	chk_1012[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int newX = x + dX_1012[i];
		int newY = y + dY_1012[i];

		if (newX < 0 || newX >= M_1012
			|| newY < 0 || newY >= N_1012)
			continue;

		if (arr_1012[newY][newX] && !chk_1012[newY][newX])
		{
			DFS_1012(newY, newX);
		}
	}
}


void Cabbage::Answer()
{
	int T = 0;
	int x, y = 0;
	int ans = 0;

	cin >> T;

	while (T-- >= 0)
	{
		memset(arr_1012, 0, sizeof(arr_1012));
		memset(chk_1012, 0, sizeof(chk_1012));

		cin >> M_1012 >> N_1012 >> K_1012;

		for (int i = 0; i < K_1012; ++i)
		{
			cin >> x >> y;
			arr_1012[y][x] = 1;
		}

		for (int i = 0; i < N_1012; ++i)
		{
			for (int j = 0; j < M_1012; ++j)
			{
				if (arr_1012[i][j] == 1 && !chk_1012[i][j])
				{
					DFS_1012(i, j);
					++ans;
				}
			}
		}
		cout << ans << '\n';
		ans = 0;
	}
}

void Cabbage::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 2040KB";
	cout << "\n 시간		: 4ms";
	cout << "\n 코드길이	: 922B";
}
