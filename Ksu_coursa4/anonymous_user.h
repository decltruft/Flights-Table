#pragma once

#include "user.h"
#include "flight_table.h"

class anonymous_user :      // ����� ���������� ������������, ����������� �� user
    public user
{
public:
    anonymous_user();

    void show_flight_table() const override;
    void choosen_parameter_sorting() override; // ����� ���������� ������� �� ���������� ���������
    void choosen_parameter_searching() override;    // ����� ������ ����� �� ���������� ���������

    void buy_ticket();
    void personal_task();

private:
    flight_table table;     // ������ ������� �� ����� �������
};

