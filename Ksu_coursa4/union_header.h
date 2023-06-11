#pragma once
                                        // union_header.h - файлик , который помогает связывать все остальные между собой чтобы не появлялся конфликт подключений 
#include "standart_class_ticket.h"
#include "business_class_ticket.h"

template<typename T>
void check_input(T& inp)    // шаблонная функция проверки ввода inp на корректность. при некорректном вводе запрашивает ввод данных еще раз
{
    if (!(std::cin >> inp))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Попробуйте ввести еще раз: ";
    }
}