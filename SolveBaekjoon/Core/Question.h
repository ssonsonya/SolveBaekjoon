#pragma once

#include "stdafx.h"
#include <time.h>

class Question
{
public:
	Question() {}
	virtual ~Question() {}

public:
	virtual void Answer() {}
	virtual void Result() {}

protected:
	clock_t start;
	clock_t end;
};