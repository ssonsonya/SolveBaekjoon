#pragma once
class SafeZone : public Question
{
public:
	SafeZone();
	~SafeZone();
public:
	void Answer() override;
	void Result() override;
};

