#pragma once

#include "stdafx.h"

class Question
{
public:
	Question() {}
	virtual ~Question() {}

public:
	virtual void Answer() {}
	virtual void Result() {}
};