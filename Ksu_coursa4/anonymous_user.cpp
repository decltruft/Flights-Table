#include "anonymous_user.h"

anonymous_user::anonymous_user() : user(), table()
{

}

void anonymous_user::buy_ticket()
{
	this->show_flight_table();
	std::cout << "\n\n";
	size_t flight_number;
	std::cout << "На какой рейс вы желаете приобрести билет: ";
	check_input(flight_number);
	table.buy_ticket(flight_number);
}

void anonymous_user::show_flight_table() const
{
	table.show_table();
}

void anonymous_user::choosen_parameter_sorting()
{
	int parameter;
	std::cout << "Парметры сортировки:\n1)По номеру рейса\n2)По стоимости бизнес-класса\n3)По стоимости стандарт-класса\nВаш выбор: ";
	check_input(parameter);			// выбираем параметр сортировки и передаем его в метод таблицы
	table.choosen_parameter_sorting(parameter);
}

void anonymous_user::choosen_parameter_searching()
{
	int parameter;
	std::cout << "Парметры поиска:\n1)По номеру рейса\n2)По пункту назначения\n3)По стоимости стандарт-класса\nВаш выбор: ";
	check_input(parameter);		// выбираем параметр сортировки и передаем его в метод таблицы
	table.choosen_parameter_searching(parameter);
}

void anonymous_user::personal_task()
{
	this->show_flight_table();
	std::cout << "\n\n";
	size_t flight_number;
	std::cout << "На какой рейс вы желаете приобрести билет: ";
	check_input(flight_number);
	size_t count_of_tickets;
	std::cout << "Введите необходимое кол-во билетов: ";
	check_input(count_of_tickets);
	table.personal_task(flight_number, count_of_tickets);
}
