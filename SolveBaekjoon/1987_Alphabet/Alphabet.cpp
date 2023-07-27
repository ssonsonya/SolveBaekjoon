#include "stdafx.h"
#include "Alphabet.h"

#include <iostream>
#include <cstring>
using namespace std;

Alphabet::Alphabet()
{
	cout << "\n ���� 1 :\n2 4\nCAAB\nADCB";
	cout << "\n ���� 2 :\n3 6\nHFDFFB\nAJHGDH\nDGAGEH";
	cout << "\n ���� 3 :\n5 5\nIEFCJ\nFHFKC\nFFALF\nHFGCF\nHMCHH";
	cout << "\n\n �Է� :\n";

	Answer();
}

static int R, C, ans;
static char arr[20][20];
static bool chk[26];

Alphabet::~Alphabet()
{
	memset(arr, '\0', sizeof(arr));
	memset(chk, false, sizeof(chk));

	int ans = 0;
}

static int dX[4] = { 0,0,1,-1 };
static int dY[4] = { 1,-1,0,0 };

static void DFS(int y, int x, int num)
{
	if (num > ans)
		ans = num;

	chk[arr[y][x] - 'A'] = true;

	for (int i = 0; i < 4; ++i)
	{
		int newX = x + dX[i];
		int newY = y + dY[i];

		if (newX < 0 || newX >= C || newY < 0 || newY >= R)
			continue;

		if (!chk[arr[newY][newX] - 'A'])
		{
			DFS(newY, newX, num + 1);
			chk[arr[newY][newX] - 'A'] = false;
		}
	}
}

void Alphabet::Answer()
{
	cin >> R >> C;

	for (int i = 0; i < R; ++i)
		cin >> arr[i];

	DFS(0, 0, 1);

	cout << ans << '\n';
}

void Alphabet::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n �޸� 	: 2020KB";
	cout << "\n �ð�		: 420ms";
	cout << "\n �ڵ����	: 616B";
}
