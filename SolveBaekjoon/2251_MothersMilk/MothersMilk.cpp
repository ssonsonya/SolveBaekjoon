#include "stdafx.h"
#include "MothersMilk.h"

#include <iostream>
#include <utility>
#include <cstring>
using namespace std;

MothersMilk::MothersMilk()
{
	cout << "\n 예제 :\n8 9 10";
	cout << "\n\n 입력 :\n";

	Answer();
}

static int A, B, C;
static bool chk[201][201][201];

static pair<Bottle, Bottle> Pour(Bottle x,Bottle y)
{
	int diff = 0;

	if (y.capacity - y.milk > x.milk)
		diff = x.milk;
	else
		diff = y.capacity - y.milk;

	x.milk -= diff;
	y.milk += diff;

	return { x,y };
}

static void DFS(Bottle a, Bottle b, Bottle c)
{
	if (chk[a.milk][b.milk][c.milk]) return;
	chk[a.milk][b.milk][c.milk] = true;

	pair<Bottle, Bottle> ab = Pour(a, b);
	DFS(ab.first, ab.second, c);

	pair<Bottle, Bottle> ac = Pour(a, c);
	DFS(ac.first, b, ac.second);

	pair<Bottle, Bottle> ba = Pour(b, a);
	DFS(ab.second, ab.first, c);

	pair<Bottle, Bottle> bc = Pour(b, c);
	DFS(a, bc.first, bc.second);

	pair<Bottle, Bottle> ca = Pour(c, a);
	DFS(ca.second, b, ca.first);

	pair<Bottle, Bottle> cb = Pour(c, b);
	DFS(a, cb.second, cb.first);
}

void MothersMilk::Answer()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);

	cin >> A >> B >> C;

	DFS({ A,0 }, { B, 0 }, { C,C });

	for (int i = 0; i <= C; ++i)
	{
		for (int j = 0; j <= B; ++j)
		{
			if (chk[0][j][i])
			{
				cout << i << " ";
				break;
			}
		}
	}
}

void MothersMilk::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 9952 KB";
	cout << "\n 시간		: 0 ms ";
	cout << "\n 코드길이	: 1135 B";
}

MothersMilk::~MothersMilk()
{
	memset(chk, false, sizeof(chk));
}
