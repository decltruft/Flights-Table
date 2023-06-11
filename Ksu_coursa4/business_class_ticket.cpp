#include "business_class_ticket.h"

business_class_ticket::business_class_ticket() : ticket()
{

}

business_class_ticket::business_class_ticket(std::tm dt, std::tm at, std::string fp)
	: ticket(dt, at, fp)
{

}
