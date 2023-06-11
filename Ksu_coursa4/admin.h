#pragma once

#include "user.h"
#include "flight_table.h"

class admin :       // класс админа. унаследован от класса user
    public user
{
public:
    admin();

    void show_flight_table() const override;    // метод отображения таблицы рейсов
    void choosen_parameter_sorting() override; // метод сортировки таблицы по выбранному параметру
    void choosen_parameter_searching() override;    // метод поиска рейса по выбранному параметру

    // admin's API
    void insert_new_flight();   // метод создания и вставки нового рейса в таблицу
    bool remove_chosen_flight();    // метод удаления выбранного рейса из таблицы

private:
    flight_table table;     // поле для хранения таблицы рейсов
};



