#pragma once

#include "ticket.h"

class standart_class_ticket :   // ����� ������������ ������ �������. ����������� ��� ����������� ������ ticket
    public ticket
{
public:
    standart_class_ticket();
    standart_class_ticket(std::tm dt, std::tm at, std::string fp);
};

