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
	case 2583:
	{
		Question* q_2583 = new FindArea();
		q_2583->Result();
		SAFE_DELETE(q_2583);
		SearchNumber();
		break;
	}
	case 2644:
	{
		Question* q_2644 = new FamilyTree();
		q_2644->Result();
		SAFE_DELETE(q_2644);
		SearchNumber();
		break;
	}
	case 1520:
	{
		Question* q_1520 = new DownHill();
		q_1520->Result();
		SAFE_DELETE(q_1520);
		SearchNumber();
		break;
	}
	case 1707:
	{
		Question* q_1707 = new BipartiteGraph();
		q_1707->Result();
		SAFE_DELETE(q_1707);
		SearchNumber();
		break;
	}
	case 2573:
	{
		Question* q_2573 = new Iceberg();
		q_2573->Result();
		SAFE_DELETE(q_2573);
		SearchNumber();
		break;
	}
	case 1967:
	{
		Question* q_1967 = new TreeDiameter_1();
		q_1967->Result();
		SAFE_DELETE(q_1967);
		SearchNumber();
		break;
	}
	case 1167:
	{
		Question* q_1167 = new TreeDiameter_2();
		q_1167->Result();
		SAFE_DELETE(q_1167);
		SearchNumber();
		break;
	}
	case 1068:
	{
		Question* q_1068 = new Tree();
		q_1068->Result();
		SAFE_DELETE(q_1068);
		SearchNumber();
		break;
	}
	case 9466:
	{
		Question* q_9466 = new TermProject();
		q_9466->Result();
		SAFE_DELETE(q_9466);
		SearchNumber();
		break;
	}
	case 1926:
	{
		Question* q_1926 = new PaintNum();
		q_1926->Result();
		SAFE_DELETE(q_1926);
		SearchNumber();
		break;
	}
	case 1325:
	{
		Question* q_1325 = new BreakingIn();
		q_1325->Result();
		SAFE_DELETE(q_1325);
		SearchNumber();
		break;
	}
	case 1937:
	{
		Question* q_1937 = new HungryPanda();
		q_1937->Result();
		SAFE_DELETE(q_1937);
		SearchNumber();
		break;
	}
	case 13023:
	{
		Question* q_13023 = new ABCDE();
		q_13023->Result();
		SAFE_DELETE(q_13023);
		SearchNumber();
		break;
	}
	case 2638:
	{
		Question* q_2638 = new Cheese();
		q_2638->Result();
		SAFE_DELETE(q_2638);
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
	cout << "\n No.   |    알고리즘구분   |    문제 이름 ";
	cout << "\n ------+-------------------+---------------";
	cout << "\n 2557  | 입출력과 사칙연산 | Hello World";
	cout << "\n 2798  |    브루트 포스    |    블랙잭 ";
	cout << "\n 2231  |    브루트 포스    |    분해합 ";
	cout << "\n 1260  |   깊이 우선 탐색  |  DFS와 BFS ";
	cout << "\n 2606  |   깊이 우선 탐색  |    바이러스 ";
	cout << "\n 2667  |   깊이 우선 탐색  | 단지번호 붙이기 ";
	cout << "\n 1012  |   깊이 우선 탐색  |   유기농 배추 ";
	cout << "\n 11724 |   깊이 우선 탐색  | 연결요소의 개수 ";
	cout << "\n 4963  |   깊이 우선 탐색  |    섬의 개수 ";
	cout << "\n 2468  |   깊이 우선 탐색  |    안전 영역 ";
	cout << "\n 11725 |   깊이 우선 탐색  | 트리의 부모 찾기 ";
	cout << "\n 1987  |   깊이 우선 탐색  |     알파벳 ";
	cout << "\n 2583  |   깊이 우선 탐색  |   영역 구하기 ";
	cout << "\n 2583  |   깊이 우선 탐색  |   영역 구하기 ";
	cout << "\n 2644  |   깊이 우선 탐색  |    촌수 계산 ";
	cout << "\n 1520  |   깊이 우선 탐색  |    내리막길 ";
	cout << "\n 1707  |   깊이 우선 탐색  |   이분그래프 ";
	cout << "\n 2573  |   깊이 우선 탐색  |      빙산 ";
	cout << "\n 1967  |   깊이 우선 탐색  |   트리의 지름 ";
	cout << "\n 1068  |   깊이 우선 탐색  |      트리 ";
	cout << "\n 9466  |   깊이 우선 탐색  |    텀 프로젝트 ";
	cout << "\n 1926  |   깊이 우선 탐색  |      그림";
	cout << "\n 1325  |   깊이 우선 탐색  |  효율적인 해킹";
	cout << "\n 1937  |   깊이 우선 탐색  |  욕심쟁이 판다";
	cout << "\n 13023 |   깊이 우선 탐색  |      ABCDE";
	cout << "\n 2638  |   깊이 우선 탐색  |      치즈";
	cout << "\n ";

	cout << '\n';
	SearchNumber();
}
