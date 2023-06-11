#pragma once
                                        // union_header.h - ������ , ������� �������� ��������� ��� ��������� ����� ����� ����� �� ��������� �������� ����������� 
#include "standart_class_ticket.h"
#include "business_class_ticket.h"

template<typename T>
void check_input(T& inp)    // ��������� ������� �������� ����� inp �� ������������. ��� ������������ ����� ����������� ���� ������ ��� ���
{
    if (!(std::cin >> inp))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "���������� ������ ��� ���: ";
    }
}