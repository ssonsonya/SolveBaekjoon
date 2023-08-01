#include "stdafx.h"
#include "Iceberg.h"

#include <iostream>
#include <cstring>
using namespace std;

Iceberg::Iceberg()
{
	cout << "\n 예제 :\n5 7\n0 0 0 0 0 0 0\n0 2 4 5 3 0 0\n0 3 0 2 5 2 0\n0 7 6 2 4 0 0\n0 0 0 0 0 0 0";
	cout << "\n\n 입력 :\n";

	Answer();
}

static int N, M;
static int iceberg[301][301];
static bool chk[301][301];
static int temp[301][301];
static int iceNum;

static int dX[4] = { -1,1,0,0 };
static int dY[4] = { 0,0,-1,1 };

static void Melt(int y, int x)
{
	for (int i = 0; i < 4; ++i)
	{
		int newX = x + dX[i];
		int newY = y + dY[i];

		if (newX < 0 || newX >= M || newY < 0 || newY >= N)
			continue;

		if (iceberg[y][x] > 0 && temp[newY][newX] == 0)
			--iceberg[y][x];
	}
}

static void DFS(int y, int x)
{
	chk[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int newX = x + dX[i];
		int newY = y + dY[i];

		if (newX < 1 || newX > M - 1 || newY < 1 || newY > N - 1)
			continue;

		if (!chk[newY][newX] && iceberg[newY][newX] > 0)
			DFS(newY, newX);
	}
}

void Iceberg::Answer()
{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);

	cin >> N >> M;
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> iceberg[i][j];
			temp[i][j] = iceberg[i][j];
		}
	}

	int years = 0;

	while (true)
	{
		iceNum = 0;
		memset(chk, false, sizeof(chk));

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (iceberg[i][j] > 0 && !chk[i][j])
				{
					DFS(i, j);
					++iceNum;
				}
			}
		}

		for (int i = 1; i < N - 1; ++i)
		{
			for (int j = 1; j < M - 1; ++j)
				Melt(i, j);
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
				temp[i][j] = iceberg[i][j];
		}

		if (iceNum == 0)
		{
			cout << 0;
			return;
		}

		if (iceNum > 1)
		{
			cout << years;
			return;
		}

		++years;
	}
}

Iceberg::~Iceberg()
{
}


void Iceberg::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 3000 KB";
	cout << "\n 시간		: 224 ms " << end - start;
	cout << "\n 코드길이	: 1466B";
}
