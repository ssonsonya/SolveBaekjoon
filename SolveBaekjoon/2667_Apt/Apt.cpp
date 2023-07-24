#include "stdafx.h"
#include "Apt.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


Apt::Apt()
{

	Answer();

}

int N_2667;
int complex_2667;
vector<int> ans_2667;
int counting_2667;
vector<string> apt_2667;
bool chk_2667[26][26];

int dX_2667[4] =
{
	-1, 1, 0, 0,
};
int dY_2667[4] =
{
	0, 0, -1, 1,
};

void DFS_2667(int x, int y)
{
	chk_2667[x][y] = true;
	++counting_2667;

	for (int i = 0; i < 4; ++i)
	{
		int newX = x + dX_2667[i];
		int newY = y + dY_2667[i];

		if (newX < 0 || newX >= N_2667
			|| newY < 0 || newY >= N_2667)
			continue;

		if (apt_2667.at(newX).at(newY) == '1' && !chk_2667[newX][newY])
			DFS_2667(newX, newY);
	}
}

void Apt::Answer()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N_2667;

	string input;

	for (int i = 0; i < N_2667; ++i)
	{
		cin >> input;
		apt_2667.push_back(input);

	}

	/*
	for (int i = 0; i < N; ++i)
	{
		cout << apt_2667->at(i) << "\n";
	}
	*/

	for (int i = 0; i < N_2667; ++i)
	{
		for (int j = 0; j < N_2667; ++j)
		{
			if (apt_2667.at(i).at(j) == '1' && !chk_2667[i][j])
			{
				DFS_2667(i, j);
				ans_2667.push_back(counting_2667);
				counting_2667 = 0;
				++complex_2667;
			}
		}
	}

	cout << complex_2667 << '\n';
	sort(ans_2667.begin(), ans_2667.end());
	for (int i = 0; i <(int)ans_2667.size(); ++i)
	{
		cout << ans_2667.at(i) << '\n';
	}
}

void Apt::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 2028KB";
	cout << "\n 시간		: 0ms";
	cout << "\n 코드길이	: 1026B";
}
