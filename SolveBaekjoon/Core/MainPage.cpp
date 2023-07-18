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

	cout << "\n 문제 번호를 입력해주세요.\n (문제조회 = 1 / 끝내기 = 0)\n 입력 : ";
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
		cout << "\n 프로그램을 종료합니다.";
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
	default:
		cout << "\n 아직 풀지 못한 문제번호입니다 :)\n 아래 목록 참고해주세요!";
		Dictionary();
	}
}

void MainPage::Dictionary()
{
	cout << "\n [문제 조회]\n";
	cout << "\n No.  |    알고리즘구분   |  문제 이름 ";
	cout << "\n -----+-------------------+-------------";
	cout << "\n 2557 | 입출력과 사칙연산 | Hello World";
	cout << "\n 2798 |    브루트 포스    |    블랙잭 ";
	cout << "\n 2231 |    브루트 포스    |    분해합 ";
	cout << "\n ";

	cout << '\n';
	SearchNumber();
}
