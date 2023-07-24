#pragma once

class Apt : public Question
{

public:
	Apt();
	~Apt() {}

public:
	virtual void Answer();
	virtual void Result();
};

