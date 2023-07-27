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
	case 2606:
	{
		Question* q_2606 = new Virus();
		q_2606->Result();
		SAFE_DELETE(q_2606);
		SearchNumber();
		break;
	}
	case 2667:
	{
		Question* q_2667 = new Apt();
		q_2667->Result();
		SAFE_DELETE(q_2667);
		SearchNumber();
		break;
	}
	case 1012:
	{
		Question* q_1012 = new Cabbage();
		q_1012->Result();
		SAFE_DELETE(q_1012);
		SearchNumber();
		break;
	}
	case 11724:
	{
		Question* q_11724 = new ConnectedComponent();
		q_11724->Result();
		SAFE_DELETE(q_11724);
		SearchNumber();
		break;
	}
	case 10026:
	{
		Question* q_10026 = new RGColorBlind();
		q_10026->Result();
		SAFE_DELETE(q_10026);
		SearchNumber();
		break;
	}
	case 4963:
	{
		Question* q_4963 = new IslandNum();
		q_4963->Result();
		SAFE_DELETE(q_4963);
		SearchNumber();
		break;
	}
	case 2468:
	{
		Question* q_2468 = new SafeZone();
		q_2468->Result();
		SAFE_DELETE(q_2468);
		SearchNumber();
		break;
	}
	case 11725:
	{
		Question* q_11725 = new FindParent();
		q_11725->Result();
		SAFE_DELETE(q_11725);
		SearchNumber();
		break;
	}
	case 1987:
	{
		Question* q_1987 = new Alphabet();
		q_1987->Result();
		SAFE_DELETE(q_1987);
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
	cout << "\n No.   |    �˰��򱸺�   |    ���� �̸� ";
	cout << "\n ------+-------------------+---------------";
	cout << "\n 2557  | ����°� ��Ģ���� | Hello World";
	cout << "\n 2798  |    ���Ʈ ����    |    ���� ";
	cout << "\n 2231  |    ���Ʈ ����    |    ������ ";
	cout << "\n 1260  |   ���� �켱 Ž��  |  DFS�� BFS ";
	cout << "\n 2606  |   ���� �켱 Ž��  |    ���̷��� ";
	cout << "\n 2667  |   ���� �켱 Ž��  | ������ȣ ���̱� ";
	cout << "\n 1012  |   ���� �켱 Ž��  |   ����� ���� ";
	cout << "\n 11724 |   ���� �켱 Ž��  | �������� ���� ";
	cout << "\n 4963  |   ���� �켱 Ž��  |    ���� ���� ";
	cout << "\n 2468  |   ���� �켱 Ž��  |    ���� ���� ";
	cout << "\n 11725 |   ���� �켱 Ž��  | Ʈ���� �θ� ã�� ";
	cout << "\n 1987  |   ���� �켱 Ž��  |     ���ĺ� ";
	cout << "\n ";

	cout << '\n';
	SearchNumber();
}
