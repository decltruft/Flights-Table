#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include "bad_opened_file.h"		// ���������� ��� �����������

class ticket	// ����� ������ - ������� ��� ������� ������� ������-����� � ��������-����� 
{
public:
	ticket();
	ticket(std::tm dt, std::tm at, std::string fp);		// ������������ ��� ������������� ��������

	// ������
	void set_departuring_time(std::tm& dt);		// ��������� ������� ������
	void set_arrival_time(std::tm& at);		// ��������� ������� ��������
	void set_finished_point(std::string &fp);	// ��������� ������ ����������

	std::string get_the_name_of_finished_point() const;		// ������� ������ ����������
	std::tm get_departurning_time() const;	// ������� ������� ��������
	std::tm get_arrival_time() const;	// ������� ������� ��������
	
	friend std::ifstream& operator>>(std::ifstream& ifs, ticket& tic);		// ������������� ������� � ����������� �������� ��������� �����-������, � ��� �� ������ � �������
	friend std::ofstream& operator<<(std::ofstream& ofs, const ticket& tic);	// ���� ������� (��� �������� � ���������� ������ )
	friend std::ostream& operator<<(std::ostream& os, const ticket& tic);
private:
	std::tm departuring_time;		// ���� � ��������� ������� ������
	std::tm arrival_time;	// ���� � ��������� ������� ��������
	std::string finished_point;		// ���� � ��������� ������ ����������
};

