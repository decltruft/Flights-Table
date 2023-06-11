#pragma once

#include "flight.h"

class flight_table
{
public:
	flight_table();		// конструктор таблицы рейсов

	void show_table() const;	// отображение таблицы рейсов в консоль
	void insert_new_flight(flight&& fl);	// вставка нового рейса в таблицу
	void choosen_parameter_sorting(int);	// метод сортировки таблицы по параметру
	void choosen_parameter_searching(int);	// метод поиска рейса по параметру
	bool remove_choosen_flight(size_t);		// удаление указанного рейса из таблицы
	bool buy_ticket(int);		// покупка билета на указанный рейс
	bool personal_task(size_t, size_t);     // индивидуальное задание по варианту : покупка нескольких билетов на указанный рейс

	~flight_table();		// деструктор класса. задает нужную последовательность при удалении элемента (в нашем случае - при завершении программы)
private:
	const std::string FILENAME = "table_of_flights.txt";	// статическая переменная, хранящая 
	std::vector<flight> flights;	// вектор хранения списка возможных рейсов

	void upload_flight_table();		// функции выгрузки в файл и загрузки из файла таблицы рейсов соответственно
	void download_flight_table();
	

};

