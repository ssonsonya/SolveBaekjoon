#include "stdafx.h"
#include "TermProject.h"

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

TermProject::TermProject()
{
	cout << "\n 예제 1:\n2\n7\n3 1 3 7 3 4 6\n8\n1 2 3 4 5 6 7 8";
	cout << "\n\n 입력 :\n";

	Answer();
}

static int num;
static int students[100001];
static int chk[100001];
static int inDFS[100001];
static int ans;

static void DFS(int index)
{
	chk[index] = true;

	if (!chk[students[index]])
		DFS(students[index]);
	else if (!inDFS[students[index]])
	{
		for (int i = students[index]; i != index; i = students[i])
			++ans;
		++ans;
	}

	inDFS[index] = true;
}

void TermProject::Answer()
{
//	std::ios::sync_with_stdio(false);
//  std::cin.tie(NULL);
//	std::cout.tie(NULL);

	int testCase = 0;
	cin >> testCase;

	while(testCase--)
	{
		cin >> num;

		for (int i = 1; i <= num; ++i)
			cin >> students[i];

		for (int i = 1; i <= num; ++i)
		{
			if (!chk[i])
				DFS(i);
		}

		cout << num - ans << '\n';

		memset(students, 0, sizeof(students));
		memset(chk, false, sizeof(chk));
		memset(inDFS, 0, sizeof(inDFS));

		ans = 0;
	}
}

TermProject::~TermProject()
{
}

void TermProject::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 8644 KB";
	cout << "\n 시간		: 80 ms ";
	cout << "\n 코드길이	: 927 B";
}
