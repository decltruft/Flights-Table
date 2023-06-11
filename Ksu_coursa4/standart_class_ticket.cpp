#include "standart_class_ticket.h"

standart_class_ticket::standart_class_ticket() : ticket()
{

}

standart_class_ticket::standart_class_ticket(std::tm dt, std::tm at, std::string fp) :
	ticket(dt,at,fp)
{

}

