#include "stdafx.h"
#include "MainPage.h"
#include <iostream>
#include <cstdlib>

#define SAFE_DELETE(p) { if(p) {delete(p); p = nullptr;}}

using namespace std;

MainPage::MainPage()
{
	cout << "\n ######     #    #######    #          #   ####     ####   #     #       ";
	cout << "\n #     #   # #   #          #  #       #  #    #   #    #  ##    #  #    ";
	cout << "\n ######   #   #  ######    #  #        # #      # #      # # #   #   #   ";
	cout << "\n #     # # ### # #         # #   #     # #      # #      # #  #  #    #  ";
	cout << "\n #     # #     # #        #   #  #     #  #    #   #    #  #   # #   #   ";
	cout << "\n ######  #     # ####### #     #  #####    ####  #  ####   #    ##  #    ";

	cout << '\n';
	SearchNumber();
}

void MainPage::SearchNumber()
{
	int input;

	cout << "\n ���� ��ȣ�� �Է����ּ���.\n (������ȸ = 1 / ������ = 0)\n �Է� : ";
	cin >> input;

	system("cls");

	CheckNumber(input);
}

void MainPage::CheckNumber(int input)
{
	switch (input)
	{
	case 0:
		MainPage::~MainPage();
		cout << "\n ���α׷��� �����մϴ�.";
		break;

	case 1:
		Dictionary();
		break;

	case 2557:
	{
		Question* q_2557 = new HelloWorld();
		q_2557->Result();
		SAFE_DELETE(q_2557);
		SearchNumber();
		break;
	}
	case 2798:
	{
		Question* q_2798 = new BlackJack();
		q_2798->Result();
		SAFE_DELETE(q_2798);
		SearchNumber();
		break;
	}
	case 2231:
	{
		Question* q_2231 = new DigitGenerator();
		q_2231->Result();
		SAFE_DELETE(q_2231);
		SearchNumber();
		break;
	}

	case 1260:
	{
		Question* q_1260 = new DFSBFS();
		q_1260->Result();
		SAFE_DELETE(q_1260);
		SearchNumber();
		break;
	}
	default:
		cout << "\n ���� Ǯ�� ���� ������ȣ�Դϴ� :)\n �Ʒ� ��� �������ּ���!";
		Dictionary();
	}
}

void MainPage::Dictionary()
{
	cout << "\n [���� ��ȸ]\n";
	cout << "\n No.  |    �˰����򱸺�   |  ���� �̸� ";
	cout << "\n -----+-------------------+-------------";
	cout << "\n 2557 | ����°� ��Ģ���� | Hello World";
	cout << "\n 2798 |    ���Ʈ ����    |    ������ ";
	cout << "\n 2231 |    ���Ʈ ����    |    ������ ";
	cout << "\n 1260 |   �׷����� ��ȸ   |  DFS�� BFS ";
	cout << "\n ";

	cout << '\n';
	SearchNumber();
}