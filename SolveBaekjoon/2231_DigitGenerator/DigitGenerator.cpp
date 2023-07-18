#include "stdafx.h"
#include "DigitGenerator.h"
#include <iostream>

using namespace std;

DigitGenerator::DigitGenerator()
{
	cout << "\n [ 2231 | ���Ʈ ���� | ������ ]\n";
	cout << "\n ���� : � �ڿ��� N�� ���� ��, �� �ڿ��� N�� �������� N�� N�� �̷�� �� �ڸ����� ���� �ǹ��Ѵ�.\n        � �ڿ��� M�� �������� N�� ���, M�� N�� �����ڶ� �Ѵ�.\n        ���� ���, 245�� �������� 256(=245+2+4+5)�� �ȴ�.\n        ���� 245�� 256�� �����ڰ� �ȴ�. ����, � �ڿ����� ��쿡�� �����ڰ� ���� ���� �ִ�.\n        �ݴ��, �����ڰ� ���� ���� �ڿ����� ���� �� �ִ�.\n        �ڿ��� N�� �־����� ��, N�� ���� ���� �����ڸ� ���س��� ���α׷��� �ۼ��Ͻÿ�.";
	cout << "\n �Է� : ù° �ٿ� �ڿ��� N(1 �� N �� 1,000,000)�� �־�����.";
	cout << "\n ��� : ù° �ٿ� ���� ����Ѵ�. �����ڰ� ���� ��쿡�� 0�� ����Ѵ�.";

	cout << "\n -----------------------------------\n\n";

	Answer();
}

void DigitGenerator::Answer()
{
	int N = 0;
	int answer = 0;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int n = i;
		int sum = 0;
		while (n > 0)
		{
			sum = sum + n % 10;
			n = n / 10;
		}
		answer = i + sum;
		if (answer == N)
		{
			cout << i;
			break;
			//return 0;
		}
	}
	cout << 0;
	//return 0;
}

void DigitGenerator::Result()
{
	cout << "\n\n -----------------------------------";

	cout << "\n �޸� 	: 2020KB";
	cout << "\n �ð�		: 8ms";
	cout << "\n �ڵ����	: 326B";
}
