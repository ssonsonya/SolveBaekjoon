#include "stdafx.h"
#include "DFSBFS.h"

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

DFSBFS::DFSBFS()
{
	cout << "\n [ 1260 | �׷��� Ž�� | DFS�� BFS ]\n";
	cout << "\n ���� : �׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.\n        ��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�,\n        �� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. ���� ��ȣ�� 1������ N�������̴�.";
	cout << "\n �Է� : ù° �ٿ� ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), Ž���� ������ ������ ��ȣ V�� �־�����.\n        ���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����. � �� ���� ���̿� ���� ���� ������ ���� �� �ִ�.\n        �Է����� �־����� ������ ������̴�.";
	cout << "\n ��� : ù° �ٿ� DFS�� ������ �����, �� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�.\n        V���� �湮�� ���� ������� ����ϸ� �ȴ�.";

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

	cout << "\n �޸� 	: 5936KB";
	cout << "\n �ð�		: 8ms";
	cout << "\n �ڵ����	: 882B";
}
