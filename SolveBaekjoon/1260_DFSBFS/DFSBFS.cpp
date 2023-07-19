#include "stdafx.h"
#include "DFSBFS.h"

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

DFSBFS::DFSBFS()
{
	cout << "\n [ 1260 | 그래프 탐색 | DFS와 BFS ]\n";
	cout << "\n 문제 : 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오.\n        단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고,\n        더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.";
	cout << "\n 입력 : 첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다.\n        다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다.\n        입력으로 주어지는 간선은 양방향이다.";
	cout << "\n 출력 : 첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다.\n        V부터 방문된 점을 순서대로 출력하면 된다.";

	cout << "\n -----------------------------------\n\n";

	Answer();
}

int arr[1001][1001];
bool visited[1001];

void DFS(int V, int N)
{
	visited[V] = true;
	cout << V << " ";

	for (int i = 1; i <= N; ++i)
	{
		if (arr[V][i] == 1 && !visited[i])
			DFS(i,N);

		if (i == N)
			return;
	}
}

void BFS(int V, int N)
{
	queue<int> q;
	q.push(V);

	while (!q.empty())
	{
		int now = q.front();
		visited[now] = true;
		cout << now << " ";
		q.pop();

		for (int i = 1; i <= N; ++i)
		{
			if (arr[now][i] == 1 && !visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

void DFSBFS::Answer()
{
	int N, M, V = 0;
	int vertex, next = 0;

	cin >> N >> M >> V;

	for (int i = 1; i <= M; ++i)
	{
		cin >> vertex >> next;
		arr[vertex][next] = 1;
		arr[next][vertex] = 1;
	}

	DFS(V, N);

	memset(visited, false, sizeof(visited));

	cout << "\n";
	BFS(V, N);
}

void DFSBFS::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 5936KB";
	cout << "\n 시간		: 8ms";
	cout << "\n 코드길이	: 882B";
}
