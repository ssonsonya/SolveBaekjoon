#include "stdafx.h"
#include "ConnectedComponent.h"

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

ConnectedComponent::ConnectedComponent()
{
	Answer();

}

static bool chk[1001];

static void DFS(int x, vector<int>* v)
{
	chk[x] = true;

	for (int i = 0; i < (int)v[x].size(); ++i)
	{
		int next = v[x].at(i);

		if (v[x].at(i) != 0 && !chk[next])
			DFS(next, v);
	}
}

void ConnectedComponent::Answer()
{
	vector<int> v[1001];
	memset(chk, false, sizeof(chk));
	int ans = 0;

	int N, M = 0;
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int x, y = 0;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 1; i < N; ++i)
	{
		if (!chk[i])
		{
			DFS(i, v);
			++ans;
		}
	}

	cout << ans << '\n';
}

void ConnectedComponent::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 2040KB";
	cout << "\n 시간		: 4ms";
	cout << "\n 코드길이	: 922B";
}
