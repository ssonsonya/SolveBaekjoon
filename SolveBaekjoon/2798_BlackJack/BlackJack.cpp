#include "stdafx.h"
#include "BlackJack.h"

#include <iostream>
#include <vector>
using namespace std;

BlackJack::BlackJack()
{
	cout << "\n [ 2798 | 브루트 포스 | 블랙 잭 ]\n";
	cout << "\n 문제 : N장의 카드에 써져 있는 숫자가 주어졌을 때,\n        M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 구해 출력하시오.";
	cout << "\n 입력 : 첫째 줄에 카드의 개수 N(3 <= N <= 100)과 M(10 <= M <= 300,000)이 주어진다.\n        둘째 줄에는 카드에 쓰여있는 수가 주어지며, 이 값은 100,000을 넘지 않는 양의 정수이다.\n        합이 M을 넘지 않는 카드 3장을 찾을 수 있는 경우만 입력으로 주어진다.";
	cout << "\n 출력 : 첫째 줄의 M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합";

	cout << "\n -----------------------------------\n\n";

	Answer();
}

void BlackJack::Answer()
{
	unsigned int n = 0, m = 0, sum = 0;
	vector<unsigned int> cards;

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		unsigned int temp;
		cin >> temp;
		cards.push_back(temp);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				if (cards[i] + cards[j] + cards[k] <= m && cards[i] + cards[j] + cards[k] >= sum)
					sum = cards[i] + cards[j] + cards[k];
			}
		}
	}

	cout << sum;
}

void BlackJack::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n 메모리 	: 2020KB";
	cout << "\n 시간		: 0ms";
	cout << "\n 코드길이	: 531B";
}
