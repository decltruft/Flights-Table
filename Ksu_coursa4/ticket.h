#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include "bad_opened_file.h"		// подключаем все необходимое

class ticket	// класс билета - базовый для классов билетов бизнес-класс и стандарт-класс 
{
public:
	ticket();
	ticket(std::tm dt, std::tm at, std::string fp);		// конструкторы для инициализации значений

	// методы
	void set_departuring_time(std::tm& dt);		// установка времени отлета
	void set_arrival_time(std::tm& at);		// установка времени прибытия
	void set_finished_point(std::string &fp);	// установка пункта назначения

	std::string get_the_name_of_finished_point() const;		// возврат пункта назначения
	std::tm get_departurning_time() const;	// возврат времени отправки
	std::tm get_arrival_time() const;	// возврат времени прибытия
	
	friend std::ifstream& operator>>(std::ifstream& ifs, ticket& tic);		// дружественные функции с перегрузкой операций файлового ввода-вывода, а так же вывода в консоль
	friend std::ofstream& operator<<(std::ofstream& ofs, const ticket& tic);	// всех билетов (для удобства и комфортног чтения )
	friend std::ostream& operator<<(std::ostream& os, const ticket& tic);
private:
	std::tm departuring_time;		// поле с хранением времени отлета
	std::tm arrival_time;	// поле с хранением времени прибытия
	std::string finished_point;		// поле с хранением пункта назначения
};

