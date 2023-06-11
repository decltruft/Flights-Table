#include "flight.h"

flight::flight() :tick(2)
{
	number_of_flight = 0;
	count_of_business_class = 0;
	count_of_standart_class = 0;
	price_of_business = 0.0;
	price_of_standart = 0.0;

	tick[0] = std::make_shared<standart_class_ticket>();
	tick[1] = std::make_shared<business_class_ticket>();
}

flight::flight(size_t nof, size_t cobc, size_t cosc, double pob, double pos, std::tm tm, std::tm at, std::string fp) : 
	number_of_flight(nof), count_of_business_class(cobc), count_of_standart_class(cosc), price_of_business(pob),
	price_of_standart(pos), tick(2)
{
	tick[0] = std::make_shared<standart_class_ticket>(tm, at, fp);
	tick[1] = std::make_shared<business_class_ticket>(tm, at, fp);
}

flight::flight(const flight& fl) : number_of_flight(fl.number_of_flight), count_of_business_class(fl.count_of_business_class),
		count_of_standart_class(fl.count_of_standart_class), price_of_business(fl.price_of_business),
		price_of_standart(fl.price_of_standart), tick(fl.tick)

{

}

flight& flight::operator=(const flight& fl)
{
	number_of_flight = fl.number_of_flight;
	count_of_business_class = fl.count_of_business_class;
	count_of_standart_class = fl.count_of_standart_class;
	price_of_business = fl.price_of_business;
	price_of_standart = fl.price_of_standart;
	tick = fl.tick;

	return *this;
}

flight::flight(flight&& fl) noexcept : number_of_flight(std::move(fl.number_of_flight)), count_of_business_class(std::move(fl.count_of_business_class)),
		count_of_standart_class(std::move(fl.count_of_standart_class)), price_of_business(std::move(fl.price_of_business)),
		price_of_standart(std::move(fl.price_of_standart)), tick(std::move(fl.tick)) 
{

}

size_t flight::get_number_of_flight() const
{
	return number_of_flight;
}

size_t flight::get_count_of_business_class() const
{
	return count_of_business_class;
}

size_t flight::get_count_of_standart_class() const
{
	return count_of_standart_class;
}

double flight::get_price_of_business() const
{
	return price_of_business;
}

double flight::get_price_of_standart() const
{
	return price_of_standart;
}

std::string flight::get_finished_point() const
{
	return tick[0]->get_the_name_of_finished_point();
}

void flight::set_count_of_business_class(size_t cobs)
{
	count_of_business_class = cobs;
}

void flight::set_count_of_standart_class(size_t cosc)
{
	count_of_standart_class = cosc;
}

std::ifstream& operator>>(std::ifstream& ifs, flight& fl)
{
	ifs >> *(fl.tick[0]) >> fl.number_of_flight >> fl.count_of_business_class >> fl.count_of_standart_class
		>> fl.price_of_business >> fl.price_of_standart;
	*(fl.tick[1]) = *(fl.tick[0]);
	return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, const flight& fl)
{
	ofs << *(fl.tick[0])  << ' ' << fl.number_of_flight << ' ' << fl.count_of_business_class << ' ' << fl.count_of_standart_class
		<< ' ' << fl.price_of_business << ' ' << fl.price_of_standart << std::endl;
	return ofs;
}

std::ostream& operator<<(std::ostream& os, const flight& fl)
{
	os << "Номер рейса: " << fl.get_number_of_flight() << "\nКол-во бизнес-классов: " << fl.count_of_business_class 
		<< "\nКол-во стандарт-классов: " << fl.count_of_standart_class << "\nЦена бизнес-класса\\стандарт-класса: " 
		<< fl.price_of_business << '\\' << fl.price_of_standart << "\n";
	os << *(fl.tick[0]);
	return os;
}


