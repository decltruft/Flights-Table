#pragma once

#include "ticket.h"

class standart_class_ticket :   // класс стандартного класса билетов. унаследовал все возможности класса ticket
    public ticket
{
public:
    standart_class_ticket();
    standart_class_ticket(std::tm dt, std::tm at, std::string fp);
};

