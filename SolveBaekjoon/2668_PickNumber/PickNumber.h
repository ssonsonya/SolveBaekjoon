#pragma once
class PickNumber : public Question
{
public:
	PickNumber();
	~PickNumber();

public:
	void Answer() override;
	void Result() override;
};

