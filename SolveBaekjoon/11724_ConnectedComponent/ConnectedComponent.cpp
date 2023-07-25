#include "stdafx.h"
#include "ConnectedComponent.h"

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

ConnectedComponent::ConnectedComponent()
{

	cout << "\n ���� 1:\n6 5\n1 2\n2 5\n5 1\n3 4\n4 6";
	cout << "\n ���� 2:\n6 8\n1 2\n2 5\n5 1\n3 4\n4 6\n5 4\n2 4\n2 3";

	cout << "\n\n �Է� :\n";

	Answer();
}

static vector<int> v[1001];
static bool chk[1001];

ConnectedComponent::~ConnectedComponent()
{
	memset(chk, false, sizeof(chk));
	for (int i = 0; i < v->size(); ++i)
	{
		v[i].clear();
	}
}

static void DFS(int x)
{
	chk[x] = true;

	for (int i = 0; i < (int)v[x].size(); ++i)
	{
		int next = v[x].at(i);

		if (next != 0 && !chk[next])
			DFS(next);
	}
}

void ConnectedComponent::Answer()
{
	int ans = 0;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int x, y = 0;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 1; i <= N; ++i)
	{
		if (!chk[i])
		{
			DFS(i);
			++ans;
		}
	}

	cout << ans;
}

void ConnectedComponent::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n �޸� 	: 6400KB";
	cout << "\n �ð�		: 308ms";
	cout << "\n �ڵ����	: 553B";
}
