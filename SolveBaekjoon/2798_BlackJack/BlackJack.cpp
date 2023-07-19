#include "stdafx.h"
#include "BlackJack.h"

#include <iostream>
#include <vector>
using namespace std;

BlackJack::BlackJack()
{
	cout << "\n [ 2798 | ���Ʈ ���� | ���� �� ]\n";
	cout << "\n ���� : N���� ī�忡 ���� �ִ� ���ڰ� �־����� ��,\n        M�� ���� �����鼭 M�� �ִ��� ����� ī�� 3���� ���� ���� ����Ͻÿ�.";
	cout << "\n �Է� : ù° �ٿ� ī���� ���� N(3 <= N <= 100)�� M(10 <= M <= 300,000)�� �־�����.\n        ��° �ٿ��� ī�忡 �����ִ� ���� �־�����, �� ���� 100,000�� ���� �ʴ� ���� �����̴�.\n        ���� M�� ���� �ʴ� ī�� 3���� ã�� �� �ִ� ��츸 �Է����� �־�����.";
	cout << "\n ��� : ù° ���� M�� ���� �����鼭 M�� �ִ��� ����� ī�� 3���� ��";

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

	cout << "\n �޸� 	: 2020KB";
	cout << "\n �ð�		: 0ms";
	cout << "\n �ڵ����	: 531B";
}