#pragma once

#include "union_header.h"

class flight		// класс описывающий 1 рейс.
{
public:
	flight();
	flight(size_t, size_t, size_t, double, double, std::tm, std::tm, std::string);
	flight(const flight&);
	flight& operator=(const flight&);
	flight(flight&&) noexcept;		// конструкторы для инициализации полей рейса

	size_t get_number_of_flight() const;	// возврат номера рейса
	size_t get_count_of_business_class() const;		// возврат кол-ва бизнес-классов
	size_t get_count_of_standart_class() const;		// возврат кол-ва стандарт-классов
	double get_price_of_business() const;	// возврат цены бизнес-класса
	double get_price_of_standart() const;	// возврат цены стандарт-класса
	std::string get_finished_point() const;

	void set_count_of_business_class(size_t);	// установка кол-ва билетов бизнес-класса
	void set_count_of_standart_class(size_t);	// установка кол-ва билетов стандарт-класса

	friend std::ifstream& operator>>(std::ifstream& ifs, flight& fl);		// дружественные функции с перегрузкой операций файлового ввода-вывода, а так же вывода в консоль
	friend std::ofstream& operator<<(std::ofstream& ofs, const flight& fl);		// всех билетов (для удобства и комфортног чтения )
	friend std::ostream& operator<<(std::ostream& os, const flight& fl);
private:
	size_t number_of_flight;		// поле хранения номера рейса
	size_t count_of_business_class;		// поле кол-ва билетов бизнес-класса
	size_t count_of_standart_class;		// поле кол-ва билетов стандарт-класса
	double price_of_business;	// поле цены бизнес-класса
	double price_of_standart;	// поле цены стандарт-класса
	std::vector<std::shared_ptr<ticket>> tick;	// вектор для хранения билетов 2 типов - станадртного и бизнес-класса. в качестве типа параметра используется
};												// указатель на базовый класс для обоих - ticket

