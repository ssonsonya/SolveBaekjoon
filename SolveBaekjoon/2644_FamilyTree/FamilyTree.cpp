#include "stdafx.h"
#include "FamilyTree.h"

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

FamilyTree::FamilyTree()
{
	cout << "\n ���� 1 :\n9\n7 3\n7\n1 2\n1 3\n2 7\n2 8\n2 9\n4 5\n4 6";
	cout << "\n ���� 2 :\n9\n8 6\n7\n1 2\n1 3\n2 7\n2 8\n2 9\n4 5\n4 6";

	cout << "\n\n �Է� :\n";

	Answer();
}

static vector<int> tree[101];
static bool chk[101];
static int ans = -1;

static void DFS(int x, int y, int num)
{
	chk[x] = true;

	if (x == y)
		ans = num;


	for (int i = 0; i < (size_t)tree[x].size(); ++i)
	{
		int next = tree[x][i];
		if (!chk[next])
			DFS(next, y, num + 1);
	}
}

void FamilyTree::Answer()
{
	int n, m, x, y = 0;

	cin >> n;
	cin >> x >> y;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b = 0;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(x, y, 0);

	cout << ans;
}

void FamilyTree::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n �޸� 	: 2024KB";
	cout << "\n �ð�		: 0ms";
	cout << "\n �ڵ����	: 532B";
}


FamilyTree::~FamilyTree()
{
	memset(tree, 0, sizeof(tree));
	memset(chk, false, sizeof(chk));
	ans = -1;
}
