#pragma once

struct Bottle {
	int capacity = 0;
	int milk = 0;
};

class MothersMilk : public Question
{

public:
	MothersMilk();
	~MothersMilk();

public:
	void Answer() override;
	void Result() override;
};

