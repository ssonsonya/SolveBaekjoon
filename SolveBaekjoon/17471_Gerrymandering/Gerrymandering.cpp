#include "stdafx.h"
#include "Gerrymandering.h"

#include <iostream>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;

Gerrymandering::Gerrymandering()
{
	cout << "\n 예제 :\n3 4 5\n3 2\n2 2\n3 1\n2 3\n1 1";
	cout << "\n\n 입력 :\n";

	Answer();
}

static int N;
static int map[11][11];
static int chk[11];
static int populations[11];
static int ans = 2e9;	// int범위내 무한 표현

static int DFS(int district, int bitmask)
{
	int res = populations[district];
	chk[district] = 1;
	for (int i = 0; i < N; ++i)
	{
		if (map[district][i + 1] && (bitmask & (1 << i)) && !chk[i + 1])
			res += DFS(i + 1, bitmask);
	}
	return res;
}

void Gerrymandering::Answer()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin>> populations[i];

	for (int i = 1, t; i <= N; ++i)
	{
		cin >> t;
		for (int j = 0, tmp; j < t; ++j)
		{
			cin>> tmp;
			map[i][tmp] = 1;
		}
	}
	
	for (int i = 1, j; i < 1 << N; ++i)
	{
		memset(chk, 0, sizeof(chk));
		int sum = 0;
		for (j = 0; j < N; ++j)
		{
			sum = DFS(j + 1, i);
			break;
		}

		for (j = 0; j < N; ++j)
		{
			if (~i & (1 << j))
			{
				sum -= DFS(j + 1, ~i);
				break;
			}
		}

		j = 1;

		while (j <= N && chk[j])
			j++;

		if (j > N)
		{
			ans = min(ans, abs(sum));
		}
	}

	cout << (ans == 2e9 ? -1 : ans);
}

void Gerrymandering::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 1164 KB";
	cout << "\n 시간		: 0 ms ";
	cout << "\n 코드길이	: 871 B";
}

Gerrymandering::~Gerrymandering()
{

}
