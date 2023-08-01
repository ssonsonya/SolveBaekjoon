#pragma once
class Iceberg : public Question
{
public:
	Iceberg();
	~Iceberg();

public:
	void Answer() override;
	void Result() override;
};

