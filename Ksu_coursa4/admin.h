#pragma once

#include "user.h"
#include "flight_table.h"

class admin :       // ����� ������. ����������� �� ������ user
    public user
{
public:
    admin();

    void show_flight_table() const override;    // ����� ����������� ������� ������
    void choosen_parameter_sorting() override; // ����� ���������� ������� �� ���������� ���������
    void choosen_parameter_searching() override;    // ����� ������ ����� �� ���������� ���������

    // admin's API
    void insert_new_flight();   // ����� �������� � ������� ������ ����� � �������
    bool remove_chosen_flight();    // ����� �������� ���������� ����� �� �������

private:
    flight_table table;     // ���� ��� �������� ������� ������
};



