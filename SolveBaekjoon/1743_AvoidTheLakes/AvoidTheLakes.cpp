#include "stdafx.h"
#include "AvoidTheLakes.h"

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

AvoidTheLakes::AvoidTheLakes()
{
	cout << "\n 예제 :\n3 4 5\n3 2\n2 2\n3 1\n2 3\n1 1";
	cout << "\n\n 입력 :\n";

	Answer();
}

static int N, M;

static bool map[101][101];
static bool chk[101][101];

static int dR[4] = { -1,1,0,0 };
static int dC[4] = { 0,0,-1,1 };

static int maxSize;
static int newSize;

static void DFS(int row, int col)
{
	chk[row][col] = true;
	++newSize;

	for (int i = 0; i < 4; ++i)
	{
		int nextR = row + dR[i];
		int nextC = col + dC[i];

		if (nextR < 1 || nextR > N || nextC < 1 || nextC > M)
			continue;

		if (!chk[nextR][nextC] && map[nextR][nextC])
			DFS(nextR, nextC);
	}
}

void AvoidTheLakes::Answer()
{
	int K = 0;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < K; ++i)
	{
		int R = 0;
		int C = 0;
		scanf("%d %d", &R, &C);

		map[R][C] = true;
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (map[i][j] && !chk[i][j])
			{
				newSize = 0;
				DFS(i, j);
				if (newSize > maxSize)
					maxSize = newSize;
			}
		}
	}

	printf("%d", maxSize);
}

void AvoidTheLakes::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 1164 KB";
	cout << "\n 시간		: 0 ms ";
	cout << "\n 코드길이	: 871 B";
}

AvoidTheLakes::~AvoidTheLakes()
{

}