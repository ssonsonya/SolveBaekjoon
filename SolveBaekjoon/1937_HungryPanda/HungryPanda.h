#pragma once
class HungryPanda : public Question
{
public:
	HungryPanda();
	~HungryPanda();

public:
	void Answer() override;
	void Result() override;
};

