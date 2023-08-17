#include "stdafx.h"
#include "PickNumber.h"

#include <iostream>
#include <vector>
using namespace std;

PickNumber::PickNumber()
{
	cout << "\n 예제 :\n7\n3\n1\n1\n5\n5\n4\n6";
	cout << "\n\n 입력 :\n";

	Answer();
}

static int numSet[101];
static bool exist[101];
static bool chk[101];

static bool DFS(int init, int prev, int next)
{
	if (init == next)
		return true;
	
	if (chk[next])
		return false;

	chk[next] = true;

	return DFS(init, next, numSet[next]);
}

void PickNumber::Answer()
{
	int N = 0;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> numSet[i];
		exist[numSet[i]] = true;
	}
	
	vector<int> ans;

	for (int i = 1; i <= N; ++i)
	{
		if (exist[i])
		{
			for (int j = 1; j <= N; ++j)
				chk[j] = false;

			if (DFS(i, i, numSet[i]))
				ans.push_back(i);
		}
	}

	cout << ans.size() << '\n';

	for (auto t : ans)
		cout << t << '\n';
}

void PickNumber::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 2020 KB";
	cout << "\n 시간		: 0 ms ";
	cout << "\n 코드길이	: 663 B";
}

PickNumber::~PickNumber()
{
	memset(numSet, 0, sizeof(numSet));
	memset(chk, false, sizeof(chk));
	memset(exist, false, sizeof(exist));
}
