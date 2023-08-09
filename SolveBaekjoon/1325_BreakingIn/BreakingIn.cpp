#include "stdafx.h"
#include "BreakingIn.h"

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

BreakingIn::BreakingIn()
{
	cout << "\n 예제 1:\n5 4\n3 1\n3 2\n4 3\n5 3";
	cout << "\n\n 입력 :\n";

	Answer();
}

static vector<int> computerSystem[100001];
static bool chk[100001];
static int hacked = 1;
static int maxHacked;

static void DFS(int computer)
{
	chk[computer] = true;

	for (int i = 0; i < computerSystem[computer].size(); ++i)
	{
		if (!chk[computerSystem[computer][i]])
		{
			DFS(computerSystem[computer][i]);
			hacked++;
		}
	}
}

void BreakingIn::Answer()
{
	int N, M = 0;

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int m, n = 0;
		cin >> m >> n;
		computerSystem[n].push_back(m);
	}

	vector<int> hackedComputer;

	for (int i = 1; i <= N; ++i)
	{
		memset(chk, false, sizeof(chk));
		DFS(i);
		hackedComputer.push_back(hacked);

		if (hacked >= maxHacked)
			maxHacked = hacked;

		hacked = 1;
	}

	for (int i = 0; i < hackedComputer.size(); ++i)
	{
		if (hackedComputer[i] == maxHacked)
			cout << i + 1 << ' ';
	}
}

BreakingIn::~BreakingIn()
{
}

void BreakingIn::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 5592 KB";
	cout << "\n 시간		: 3220 ms ";
	cout << "\n 코드길이	: 869 B";
}
