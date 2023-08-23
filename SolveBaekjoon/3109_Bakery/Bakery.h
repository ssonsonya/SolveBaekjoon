#pragma once
class Bakery :public Question
{
public:
	Bakery();
	~Bakery();

public:
	void Answer() override;
	void Result() override;

};

