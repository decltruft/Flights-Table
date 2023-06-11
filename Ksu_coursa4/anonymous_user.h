#pragma once

#include "user.h"
#include "flight_table.h"

class anonymous_user :      // класс анонимного пользователя, унаследован от user
    public user
{
public:
    anonymous_user();

    void show_flight_table() const override;
    void choosen_parameter_sorting() override; // метод сортировки таблицы по выбранному параметру
    void choosen_parameter_searching() override;    // метод поиска рейса по выбранному параметру

    void buy_ticket();
    void personal_task();

private:
    flight_table table;     // хранит таблицу со всеми рейсами
};

