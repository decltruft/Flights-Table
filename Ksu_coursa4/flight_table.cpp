#include "flight_table.h"

flight_table::flight_table()
{
	download_flight_table();		// � ������������ �������� ������� �������� �� ����� � ������ ������� ������
}

void flight_table::show_table() const
{
	std::cout << "\t\t\t\t\t������ ���� ��������� ���������:\n\n\n";
	for (auto &it : flights)
	{
		std::cout << it << std::endl;		// ����������� �� ������� � ������� �� ����� ������� ���� � ������ �����
	}
}

void flight_table::insert_new_flight(flight&& fl)
{
	flights.push_back(fl);		// ��������� � ������ ����� ����
}

void flight_table::choosen_parameter_sorting(int parameter)
{
	switch (parameter)
	{
	case 1:
		std::sort(flights.begin(), flights.end(), [](flight& f1, flight& f2) { return (f1.get_number_of_flight() < f2.get_number_of_flight()); });
		break;
	case 2:
		std::sort(flights.begin(), flights.end(), [](flight& f1, flight& f2) { return (f1.get_price_of_business() < f2.get_price_of_business()); });
		break;
	case 3:
		std::sort(flights.begin(), flights.end(), [](flight& f1, flight& f2) { return (f1.get_price_of_standart() < f2.get_price_of_standart()); });
		break;
	default: std::cout << "�������� ������ �������!\n";
	}
}

void flight_table::choosen_parameter_searching(int parameter)
{
	std::string finished_point;
	switch (parameter)
	{
	case 1:
		size_t number_of_flight;
		std::cout << "������� ����� ����� ��� ������: ";
		check_input(number_of_flight);
		for (auto& it : flights)
		{
			if (it.get_number_of_flight() == number_of_flight)
				std::cout << it << std::endl;
		}
		break;
	case 2:
		std::cin.get();
		std::cout << "������� �������� ������ ���������� �����: ";
		std::getline(std::cin, finished_point);
		for (auto& it : flights)
		{
			if (it.get_finished_point() == finished_point)
				std::cout << it << std::endl;
		}
		break;
	case 3:
		double price_of_business;
		std::cout << "������� ���� ��������-������ ��� ������: ";
		check_input(price_of_business);
		for (auto& it : flights)
		{
			if (it.get_price_of_standart() == price_of_business)
				std::cout << it << std::endl;
		}
		break;
	default: std::cout << "�������� ������ �������!\n";
	}
}

bool flight_table::remove_choosen_flight(size_t removing_flight)
{
	for (std::vector<flight>::const_iterator it = flights.begin(); it != flights.end(); ++it)
	{
		if(it->get_number_of_flight() == removing_flight)		// ���� ����� ����� ��������� � ������� ���������� - ������� ��� �� �������
		{
			flights.erase(it);
			return true;
		}
	}
	return false;
}

bool flight_table::buy_ticket(int fn)
{
	size_t type_of_ticket;
	for (auto &it : flights)
	{
		if (it.get_number_of_flight() == fn)
		{
			if ((it.get_count_of_business_class() == 0) && (it.get_count_of_standart_class() == 0))
			{
				std::cout << "������� � ����� ������� ����� ������ ���!\n";
				return false;
			}
			std::cout << "���� ����� " << fn << " ����� " << it.get_count_of_business_class()
				<< " ������� ������-������ �� ���� " << it.get_price_of_business() << "$ �� �����\n� " << it.get_count_of_standart_class()
				<< " ������� ��������-������ �� ���� " << it.get_price_of_standart() << " $ �� �����. ��� ������� �������(1/2): ";
			check_input(type_of_ticket);
			switch (type_of_ticket)
			{
			case 1:
				if (it.get_count_of_business_class() == 0)
				{
					std::cout << "������ ������� ������ �����������!\n";
					break;
				}
				it.set_count_of_business_class(it.get_count_of_business_class() - 1);
				std::cout << "������� ��������� �������!\n";
				break;
			case 2:
				if (it.get_count_of_standart_class() == 0)
				{
					std::cout << "������ ������� ������ �����������!\n";
					break;
				}
				it.set_count_of_standart_class(it.get_count_of_standart_class() - 1);
				std::cout << "������� ��������� �������!\n";
				break;
			}
			return true;
		}
	}
	std::cout << "��������� ���� ���� �� ��� ������!\n";
	return false;
}

bool flight_table::personal_task(size_t fn, size_t cot)
{
	size_t type_of_ticket;
	size_t choice;
	for (auto &it : flights)
	{
		if (it.get_number_of_flight() == fn)
		{
			if ((it.get_count_of_business_class() == 0) && (it.get_count_of_standart_class() == 0))
			{
				std::cout << "������� � ����� ������� ����� ������ ���!\n";
				return false;
			}
			std::cout << "���� ����� " << fn << " ����� " << it.get_count_of_business_class()
				<< " ������� ������-������ �� ���� " << it.get_price_of_business() << "$ �� �����\n� " << it.get_count_of_standart_class()
				<< " ������� ��������-������ �� ���� " << it.get_price_of_standart() << " $ �� �����. ��� ������� �������(1/2): ";
			check_input(type_of_ticket);
			switch (type_of_ticket)
			{
			case 1:
				if (it.get_count_of_business_class() < cot)
				{
					std::cout << "������ ������� ������ ������������!\n� ������� " << it.get_count_of_standart_class() 
						<< " ������� ��������-������. ������� ���������� ��������� ���? (��-��� 1/2): ";
					check_input(choice);
					switch (choice)
					{
					case 1:
						if (it.get_count_of_standart_class() < cot)
						{
							std::cout << "������� ��������-������ ��� �� ���������, ��� ����� �������� �������.\n";
							it.set_count_of_business_class(0);
							it.set_count_of_standart_class(0);
						}
						else
						{
							cot -= it.get_count_of_business_class();
							it.set_count_of_business_class(0);
							it.set_count_of_standart_class(it.get_count_of_standart_class() - cot);
							std::cout << "������� ��������� �������!\n";
						}
						break;
					default: break;
					}
					break;
				}
				it.set_count_of_business_class(it.get_count_of_business_class() - cot);
				std::cout << "������� ��������� �������!\n";
				break;
			case 2:
				if (it.get_count_of_standart_class() < cot)
				{
					std::cout << "������ ������� ������ ������������! � ������� " << it.get_count_of_business_class()
						<< " ������� ������-������. ������� ���������� ��������� ���? (��-��� 1\2): ";
					check_input(choice);
					switch (choice)
					{
					case 1:
						if (it.get_count_of_business_class() < cot)
						{
							std::cout << "������� ������-������ ��� �� ���������, ��� ����� �������� �������.\n";
							it.set_count_of_business_class(0);
							it.set_count_of_standart_class(0);
						}
						else
						{
							cot -= it.get_count_of_standart_class();
							it.set_count_of_standart_class(0);
							it.set_count_of_business_class(it.get_count_of_business_class() - cot);
							std::cout << "������� ��������� �������!\n";
						}
						break;
					default: break;
					}
					break;
				}
				it.set_count_of_standart_class(it.get_count_of_standart_class() - cot);
				std::cout << "������� ��������� �������!\n";
				break;
			default: std::cout << "������������ ���� ������!\n";
			}
			return true;
		}
	}
	std::cout << "��������� ���� ���� �� ��� ������!\n";
	return false;
}

void flight_table::upload_flight_table()
{
	std::ofstream ofs("new.txt");
	if (!ofs.is_open())
		throw bad_opened_file();		// ���� ��������� ���� �� ������� �������, �� ������� ���������� � ����������� � �������
	for (auto it : flights)
    	ofs << it;			// �������� �� ������� � ���������� � ���� ������ ����
	ofs.close();
	std::remove(flight_table::FILENAME.c_str());			// ������� ������ ���� � ��������������� ���������
	std::rename("new.txt", flight_table::FILENAME.c_str());
}

void flight_table::download_flight_table()
{
	std::ifstream ifs(flight_table::FILENAME);
	if (!ifs.is_open())
		throw bad_opened_file();

	std::tm departuring_time;
	std::tm arrival_time;
	std::string finished_point;
	size_t number_of_flight;
	size_t count_of_business_class;
	size_t count_of_standart_class;
	double price_of_business;
	double price_of_standart;

	while (ifs >> departuring_time.tm_mon >> departuring_time.tm_mday >> departuring_time.tm_hour >> departuring_time.tm_min
		>> arrival_time.tm_mon >> arrival_time.tm_mday >> arrival_time.tm_hour >> arrival_time.tm_min
		>> finished_point >> number_of_flight >> count_of_business_class >> count_of_standart_class
		>> price_of_business >> price_of_standart)		// ���������� ������ �� ����� �� ��� ���, ���� �� ���������� ��� ������� ������
	{
		flights.push_back(flight(number_of_flight, count_of_business_class, count_of_standart_class, 
			price_of_business, price_of_standart, departuring_time, arrival_time, finished_point));		// ����� �������� ��������� ������ � ������ ������
	}
}

flight_table::~flight_table()
{
	upload_flight_table();		// � ����������� �������� ������� �������� �� ������� ������ ������� ����� � ���� table_of_flight.txt
}