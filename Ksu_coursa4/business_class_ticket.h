#pragma once

#include "ticket.h"

class business_class_ticket :    // ����� ������-������ �������. ����������� ��� ����������� ������ ticket
    public ticket
{
public:
    business_class_ticket();
    business_class_ticket(std::tm dt, std::tm at, std::string fp);
};

