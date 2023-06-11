#pragma once

#include "ticket.h"

class business_class_ticket :    // класс бизнес-класса билетов. унаследовал все возможности класса ticket
    public ticket
{
public:
    business_class_ticket();
    business_class_ticket(std::tm dt, std::tm at, std::string fp);
};

