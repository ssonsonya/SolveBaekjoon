#include "stdafx.h"
#include "BipartiteGraph.h"

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

BipartiteGraph::BipartiteGraph()
{
	cout << "\n 예제 :\n2\n3 2\n1 3\n2 3\n4 4\n1 2\n2 3\n3 4\n4 2";
	cout << "\n\n 입력 :\n";

	Answer();
}

#define RED 1
#define BLUE 2

static int V;
static vector<int> graph[20001];
static int chk[20001];

static void DFS(int start)
{
	if(!chk[start])
		chk[start] = RED;

	for (int i = 0; i < graph[start].size(); ++i)
	{
		if (!chk[graph[start][i]])
		{
			if (chk[start] == RED)
				chk[graph[start][i]] = BLUE;
			else if (chk[start] == BLUE)
				chk[graph[start][i]] = RED;

			DFS(graph[start][i]);
		}
	}
}

static bool isBipartiteGraph()
{
	for (int i = 1; i <= V; ++i)
	{
		for (int j = 0; j < graph[i].size(); ++j)
		{
			if (chk[i] == chk[graph[i][j]])
				return 0;
		}
	}
	return 1;
}

void BipartiteGraph::Answer()
{
	int K = 0;
	cin >> K;

	while (K--)
	{
		int E = 0;

		cin >> V >> E;
		for (int i = 0; i < E; ++i)
		{
			int  x, y = 0;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		for (int i = 1; i <= V; ++i)
		{
			if (!chk[i])
				DFS(i);
		}

		if (isBipartiteGraph())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

		for (int i = 1; i <= V; i++)
			graph[i].clear();

		memset(chk, false, sizeof(chk));
	}
}

void BipartiteGraph::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 11300 KB";
	cout << "\n 시간		: 756 ms ";
	cout << "\n 코드길이	: 753B";
}
