#pragma once

#include "union_header.h"

class user		// класс пользователя - базовый родительский для классов админа и анонимного юзера 
{
public:
	virtual void show_flight_table() const = 0;
	virtual void choosen_parameter_sorting() = 0;
	virtual void choosen_parameter_searching() = 0;
};

