#pragma once

#include "union_header.h"

class flight		// ����� ����������� 1 ����.
{
public:
	flight();
	flight(size_t, size_t, size_t, double, double, std::tm, std::tm, std::string);
	flight(const flight&);
	flight& operator=(const flight&);
	flight(flight&&) noexcept;		// ������������ ��� ������������� ����� �����

	size_t get_number_of_flight() const;	// ������� ������ �����
	size_t get_count_of_business_class() const;		// ������� ���-�� ������-�������
	size_t get_count_of_standart_class() const;		// ������� ���-�� ��������-�������
	double get_price_of_business() const;	// ������� ���� ������-������
	double get_price_of_standart() const;	// ������� ���� ��������-������
	std::string get_finished_point() const;

	void set_count_of_business_class(size_t);	// ��������� ���-�� ������� ������-������
	void set_count_of_standart_class(size_t);	// ��������� ���-�� ������� ��������-������

	friend std::ifstream& operator>>(std::ifstream& ifs, flight& fl);		// ������������� ������� � ����������� �������� ��������� �����-������, � ��� �� ������ � �������
	friend std::ofstream& operator<<(std::ofstream& ofs, const flight& fl);		// ���� ������� (��� �������� � ���������� ������ )
	friend std::ostream& operator<<(std::ostream& os, const flight& fl);
private:
	size_t number_of_flight;		// ���� �������� ������ �����
	size_t count_of_business_class;		// ���� ���-�� ������� ������-������
	size_t count_of_standart_class;		// ���� ���-�� ������� ��������-������
	double price_of_business;	// ���� ���� ������-������
	double price_of_standart;	// ���� ���� ��������-������
	std::vector<std::shared_ptr<ticket>> tick;	// ������ ��� �������� ������� 2 ����� - ������������ � ������-������. � �������� ���� ��������� ������������
};												// ��������� �� ������� ����� ��� ����� - ticket

