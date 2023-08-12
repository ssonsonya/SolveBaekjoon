#include "stdafx.h"
#include "ABCDE.h"

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

ABCDE::ABCDE()
{
	cout << "\n 예제 1 :\n5 4\n0 1\n1 2\n2 3\n3 4";
	cout << "\n 예제 2 :\n5 5\n0 1\n1 2\n2 3\n3 0\n1 4";
	cout << "\n 예제 3 :\n6 5\n0 1\n0 2\n0 3\n0 4\n0 5";
	cout << "\n 예제 4 :\n8 8\n1 7\n3 7\n4 7\n3 4\n4 6\n3 5\n0 4\n2 7";
	cout << "\n\n 입력 :\n";

	Answer();
}

static vector<int> friends[2001];
static bool chk[2001];
static bool finished;

static void DFS(int friendNum, int depth)
{
	if (depth == 4)
	{
		finished = true;
		return;
	}

	chk[friendNum] = true;

	for (int i = 0; i < friends[friendNum].size(); ++i)
	{
		if (!chk[friends[friendNum][i]] && !finished)
			DFS(friends[friendNum][i], depth + 1);
	}
	chk[friendNum] = false;
}

void ABCDE::Answer()
{
	int N, M = 0;
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a, b = 0;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	for (int i = 0; i < N; ++i)
	{
		DFS(i,0);

		if (finished)
			break;
	}

	cout << finished;
}

ABCDE::~ABCDE()
{
	finished = false;
	memset(chk, false, sizeof(chk));
	for (int i = 0; i < 2001; ++i)
	{
		friends[i].clear();
	}
}

void ABCDE::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 2200 KB";
	cout << "\n 시간		: 28 ms ";
	cout << "\n 코드길이	: 731 B";
}
