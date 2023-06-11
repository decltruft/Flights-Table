#pragma once

#include "flight.h"

class flight_table
{
public:
	flight_table();		// ����������� ������� ������

	void show_table() const;	// ����������� ������� ������ � �������
	void insert_new_flight(flight&& fl);	// ������� ������ ����� � �������
	void choosen_parameter_sorting(int);	// ����� ���������� ������� �� ���������
	void choosen_parameter_searching(int);	// ����� ������ ����� �� ���������
	bool remove_choosen_flight(size_t);		// �������� ���������� ����� �� �������
	bool buy_ticket(int);		// ������� ������ �� ��������� ����
	bool personal_task(size_t, size_t);     // �������������� ������� �� �������� : ������� ���������� ������� �� ��������� ����

	~flight_table();		// ���������� ������. ������ ������ ������������������ ��� �������� �������� (� ����� ������ - ��� ���������� ���������)
private:
	const std::string FILENAME = "table_of_flights.txt";	// ����������� ����������, �������� 
	std::vector<flight> flights;	// ������ �������� ������ ��������� ������

	void upload_flight_table();		// ������� �������� � ���� � �������� �� ����� ������� ������ ��������������
	void download_flight_table();
	

};

