#include "stdafx.h"
#include "Tree.h"

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

Tree::Tree()
{
	cout << "\n 예제 1:\n5\n-1 0 0 1 1\n2";
	cout << "\n 예제 2:\n5\n-1 0 0 1 1\n1";
	cout << "\n 예제 3:\n5\n-1 0 0 1 1\n0";
	cout << "\n 예제 4:\n9\n-1 0 0 2 2 4 4 6 6\n4";
	cout << "\n\n 입력 :\n";

	Answer();
}

static vector<int> tree[50];
static bool chk[50];
static int ans;

static void DFS(int node)
{
	if (chk[node])
		return;

	chk[node] = true;
	bool isLeaf = true;

	for (int i = 0; i < (int)tree[node].size(); ++i)
	{
		if (!chk[tree[node][i]])
		{
			DFS(tree[node][i]);
			isLeaf = false;
		}
	}
	if (isLeaf)
		ans++;
}

void Tree::Answer()
{
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(NULL);
	int N;
	cin >> N;
	
	int root = 0;

	for (int i = 0; i < N; ++i)
	{
		int parent = 0;
		cin >> parent;

		if (parent == -1)
			root = i;
		else
			tree[parent].push_back(i);
	}

	int del = 0;
	cin >> del;
	chk[del] = true;

	DFS(root);

	cout << ans;
}

Tree::~Tree()
{
}

void Tree::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 2020 KB";
	cout << "\n 시간		: 0 ms ";
	cout << "\n 코드길이	: 698 B";
}
