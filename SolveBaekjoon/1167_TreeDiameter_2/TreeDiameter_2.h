#pragma once


class TreeDiameter_2 : public Question
{
public:
	struct Node
	{
		int node = 0;
		int branch = 0;
	};

public:
	TreeDiameter_2();
	~TreeDiameter_2();

public:
	void Answer() override;
	void Result() override;
};

