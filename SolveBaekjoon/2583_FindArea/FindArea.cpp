#include "stdafx.h"
#include "FindArea.h"

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

FindArea::FindArea()
{
	cout << "\n 예제 :\n5 7 3\n0 2 4 4\n1 1 2 5\n4 0 6 2";
	cout << "\n\n 입력 :\n";

	Answer();
}

static int M, N;
static bool paper[100][100];
static bool chk[100][100];

static int dX[4] = { -1,1,0,0 };
static int dY[4] = { 0,0,-1,1 };

static int DFS(int y, int x)
{
	chk[y][x] = true;
	int num = 1;

	for (int i = 0; i < 4; ++i)
	{
		int newX = x + dX[i];
		int newY = y + dY[i];

		if (newX < 0 || newX >= N || newY < 0 || newY >= M)
			continue;

		if (!chk[newY][newX] && !paper[newY][newX])
			num += DFS(newY, newX);
	}

	return num;
}

void FindArea::Answer()
{
	int K = 0;
	vector<int> ans;
	cin >> M >> N >> K;

	for (int i = 0; i < K; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; ++j)
		{
			for (int k = x1; k < x2; ++k)
				paper[j][k] = true;
		}
	}

	for (int j = 0; j < M; ++j)
	{
		for (int k = 0; k < N; ++k)
			cout << chk[j][k] << ' ';
		cout << '\n';
	}

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!chk[i][j] && !paper[i][j])
				ans.push_back(DFS(i, j));
		}
	}

	for (int j = 0; j < M; ++j)
	{
		for (int k = 0; k < N; ++k)
			cout << chk[j][k] << ' ';
		cout << '\n';
	}

	cout << ans.size() <<'\n';

	sort(ans.begin(), ans.end());

	for (auto a : ans)
		cout << a << ' ';

}

void FindArea::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 2388KB";
	cout << "\n 시간		: 0ms";
	cout << "\n 코드길이	: 948B";
}


FindArea::~FindArea()
{
	memset(paper, false, sizeof(paper));
	memset(chk, false, sizeof(chk));
}
