#include "stdafx.h"
#include "TreeDiameter_1.h"

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

TreeDiameter_1::TreeDiameter_1()
{
	cout << "\n 예제 :\n12\n1 2 3\n1 3 2\n2 4 5\n3 5 11\n3 6 9\n4 7 1\n4 8 7\n5 9 15\n5 10 4\n6 11 6\n6 12 10";
	cout << "\n\n 입력 :\n";

	Answer();
}

static vector<pair<int,int>> tree[10001];
static bool chk[10001];
static int diameter;
static int farestNode;

static void DFS(int node, int distance)
{
	chk[node] = true;

	if (distance > diameter)
	{
		diameter = distance;
		farestNode = node;
	}

	for (int i = 0; i < (size_t)tree[node].size(); ++i)
	{
		if (!chk[tree[node][i].first])
			DFS(tree[node][i].first, distance + tree[node][i].second);
	}
}

void TreeDiameter_1::Answer()
{
	//	std::ios::sync_with_stdio(false);
	//	std::cin.tie(NULL);

	int n;

	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		int a, b, c;

		cin >> a >> b >> c;

		tree[a].push_back(make_pair(b, c));
		tree[b].push_back(make_pair(a, c));
	}

	DFS(1, 0);

	diameter = 0;

	memset(chk, false, sizeof(chk));

	DFS(farestNode, 0);

	cout << diameter;
}

TreeDiameter_1::~TreeDiameter_1()
{
}

void TreeDiameter_1::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 3004 KB";
	cout << "\n 시간		: 4 ms ";
	cout << "\n 코드길이	: 805 B";
}
