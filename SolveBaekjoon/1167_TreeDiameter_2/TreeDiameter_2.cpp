#include "stdafx.h"
#include "TreeDiameter_2.h"

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

TreeDiameter_2::TreeDiameter_2()
{
	cout << "\n 예제 1:\n5\n1 3 2 -1\n2 4 4 -1\n3 1 2 4 3 -1\n4 2 4 3 3 5 6 -1\n5 4 6 -1";
	cout << "\n\n 입력 :\n";

	Answer();
}

static vector<TreeDiameter_2::Node> tree[100001];
static bool chk[100001];
static int farestNode;
static int diameter;

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
		if (!chk[tree[node][i].node])
		{
			DFS(tree[node][i].node, distance + tree[node][i].branch);
		}
	}
}

void TreeDiameter_2::Answer()
{
//	std::ios::sync_with_stdio(false);
//  std::cin.tie(NULL);

	int V = 0;

	cin >> V;

	for (int i = 0; i < V; ++i)
	{
		int par = 0;
		cin >> par;

		Node node;

		while (true)
		{
			cin >> node.node;

			if (node.node == -1)
				break;

			cin >> node.branch;

			tree[par].push_back(node);
		}
	}

	DFS(1,0);

	diameter = 0;
	memset(chk, false, sizeof(chk));

	DFS(farestNode, 0);

	cout << diameter;
}

TreeDiameter_2::~TreeDiameter_2()
{

}

void TreeDiameter_2::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 8644 KB";
	cout << "\n 시간		: 80 ms ";
	cout << "\n 코드길이	: 927 B";
}

