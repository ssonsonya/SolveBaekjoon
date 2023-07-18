#pragma once

class HelloWorld : public Question
{
public:
	HelloWorld();
	~HelloWorld() {}

public:
	virtual void Answer();
	virtual void Result();
};

