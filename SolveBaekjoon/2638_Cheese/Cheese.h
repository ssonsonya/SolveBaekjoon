#pragma once

struct Grid
{
	int cheese = 0;
	int surAir = 0;
};

class Cheese : public Question
{
public:
	Cheese();
	~Cheese();

public:
	void Answer() override;
	void Result() override;
};

