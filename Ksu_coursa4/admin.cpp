#include "admin.h"

admin::admin() : user(), table()
{

}

void admin::show_flight_table() const
{
	table.show_table();
}

void admin::choosen_parameter_sorting()
{
    int parameter;
	std::cout << "�������� ����������:\n1)�� ������ �����\n2)�� ��������� ������-������\n3)�� ��������� ��������-������\n��� �����: ";
	check_input(parameter);		// �������� �������� ����������
	table.choosen_parameter_sorting(parameter);	// �������� ��� � ����� ����� �������
}

void admin::choosen_parameter_searching()
{
	int parameter;
	std::cout << "�������� ������:\n1)�� ������ �����\n2)�� ������ ����������\n3)�� ��������� ��������-������\n��� �����: ";
	check_input(parameter);		// �������� �������� ������
	table.choosen_parameter_searching(parameter);	// �������� ��� � ����� ����� �������
}

void admin::insert_new_flight()
{
	size_t number_of_flight;
	size_t count_of_business_class;
	size_t count_of_standart_class;
	double price_of_business;
	double price_of_standart;
	std::tm departuring_time;
	std::tm arrival_time;
	std::string finished_point;

	std::cout << "������� ����� ������ �����: ";
	check_input(number_of_flight);
	std::cout << "���-�� ������� ������-������: ";
	check_input(count_of_business_class);
	std::cout << "���-�� ������� ������������ ������: ";
	check_input(count_of_standart_class);
	std::cout << "��������� ������ ������-������: ";
	check_input(price_of_business);
	std::cout << "��������� ������ ������������ ������: ";
	check_input(price_of_standart);
	std::cin.get();
	std::cout << "������������ ������ ����������: ";
	std::getline(std::cin, finished_point);
	std::cout << "���� ������ (� ������� �����/����/���/������): ";
	check_input(departuring_time.tm_mon);
	check_input(departuring_time.tm_mday);
	check_input(departuring_time.tm_hour);
	check_input(departuring_time.tm_min);
	std::cout << "���� ������� (� ������� �����/����/���/������): ";
	check_input(arrival_time.tm_mon);
	check_input(arrival_time.tm_mday);
	check_input(arrival_time.tm_hour);
	check_input(arrival_time.tm_min);

	table.insert_new_flight(flight(number_of_flight, count_of_business_class, count_of_standart_class, price_of_business,
		price_of_standart, departuring_time, arrival_time, finished_point));
}

bool admin::remove_chosen_flight()
{
	size_t removing_flight;
	std::cout << "������� ��������� ����� �����: ";
	check_input(removing_flight);
	return table.remove_choosen_flight(removing_flight);
}
