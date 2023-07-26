#include "stdafx.h"
#include "FindParent.h"

#include <iostream>
#include <vector>
using namespace std;

FindParent::FindParent()
{
	cout << "\n 예제 1 :\n7\n1 6\n6 3\n3 5\n4 1\n2 4\n4 7";

	cout << "\n 예제 2 :\n12\n1 2\n1 3\n2 4\n3 5\n3 6\n4 7\n4 8\n5 9\n5 10\n6 11\n6 12";

	cout << "\n\n 입력 :\n";

	Answer();
}

static vector<vector<int>> vec;
static int parent[100001];

static void DFS(int node)
{
	for (int i = 0; i < vec[node].size(); ++i)
	{
		int next = vec[node].at(i);
		if (parent[next] == 0)
		{
			parent[next] = node;
			DFS(next);
		}
	}
}

void FindParent::Answer()
{
	int N = 0;
	cin >> N;
	vec.assign((size_t)N + 1, vector<int>());

	for (int i = 0; i < N - 1; ++i)
	{
		int a, b = 0;
		cin >> a >> b;

		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	DFS(1);

	for (int i = 2; i <= N; ++i)
		cout << parent[i] << '\n';
}

void FindParent::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 10796KB";
	cout << "\n 시간		: 112ms";
	cout << "\n 코드길이	: 554B";
}
